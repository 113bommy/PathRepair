#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
map<long long, vector<pair<long long, long long> > > row, col;
map<long long, vector<pair<long long, long long> > > rr, cc;
map<long long, long long> rtot, ctot;
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 0; i < k; i++) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      if (y1 > y2) {
        swap(y1, y2);
      }
      row[x1].push_back({y1, y2});
    } else {
      if (x1 > x2) {
        swap(x1, x2);
      }
      col[y1].push_back({x1, x2});
    }
  }
  long long ans = 0;
  long long rc = n - 1;
  long long unr = 1;
  for (auto v : row) {
    rc--;
    if (v.first == unr) {
      unr++;
    }
    vector<pair<long long, long long> > vect = v.second;
    sort(vect.begin(), vect.end());
    long long cur = 0;
    long long tot = 0;
    for (pair<long long, long long> p : vect) {
      long long s = p.first;
      long long e = p.second;
      if (s > cur) {
        rr[v.first].push_back({s - cur, cur});
        tot += (s - cur);
      }
      cur = max(cur, e);
    }
    tot += (m - cur);
    rtot[v.first] = tot;
    rr[v.first].push_back({m - cur, cur});
    ans ^= (tot);
  }
  if (rc % 2) {
    rr[unr].push_back({m, 0});
    rtot[unr] = m;
    ans ^= m;
  }
  long long ccc = m - 1;
  long long unc = 1;
  for (auto v : col) {
    ccc--;
    if (v.first == unc) {
      unc++;
    }
    vector<pair<long long, long long> > vect = v.second;
    sort(vect.begin(), vect.end());
    long long cur = 0;
    long long tot = 0;
    for (pair<long long, long long> p : vect) {
      long long s = p.first;
      long long e = p.second;
      if (s > cur) {
        cc[v.first].push_back({s - cur, cur});
        tot += (s - cur);
      }
      cur = max(cur, e);
    }
    tot += (n - cur);
    ctot[v.first] = tot;
    cc[v.first].push_back({n - cur, cur});
    ans ^= (tot);
  }
  if (ccc % 2) {
    cc[unc].push_back({n, 0});
    ctot[unc] = n;
    ans ^= n;
  }
  if (ans == 0) {
    cout << "SECOND\n";
    return 0;
  }
  cout << "FIRST\n";
  for (auto v : rr) {
    long long rn = v.first;
    if ((rtot[rn] ^ ans) > rtot[rn]) {
      continue;
    }
    long long strip = rtot[rn] - (rtot[rn] ^ ans);
    for (auto p : v.second) {
      long long len = p.first;
      if (len >= strip) {
        long long strip_len = strip;
        cout << rn << " " << 0 << " " << rn << " " << (p.second + strip_len);
        return 0;
      } else {
        strip -= len;
      }
    }
  }
  for (auto v : rr) {
    long long cn = v.first;
    if ((ctot[cn] ^ ans) > ctot[cn]) {
      continue;
    }
    long long strip = ctot[cn] - (ctot[cn] ^ ans);
    for (auto p : v.second) {
      long long len = p.first;
      if (len >= strip) {
        long long strip_len = strip;
        cout << 0 << " " << cn << " " << (p.second + strip_len) << " " << cn;
        return 0;
      } else {
        strip -= len;
      }
    }
  }
  return 0;
}
