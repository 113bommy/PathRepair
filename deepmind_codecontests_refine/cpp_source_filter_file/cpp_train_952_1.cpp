#include <bits/stdc++.h>
using namespace std;
int n;
long long int L, al[1000], ar[1000];
map<long long int, long long int> M[1000], M2[1000];
long long int query(int i, long long int x) {
  if (M[i].count(x)) return M[i][x];
  long long int y;
  cout << "? " << i + 1 << " " << x << endl;
  cin >> y;
  M[i][x] = y, M2[i][y] = x;
  return y;
}
long long int pos(int i, long long int y) {
  auto it = M2[i].lower_bound(y);
  if ((it != M2[i].end()) && (it->first == y)) return it->second;
  long long int s = 0, e = 1e18;
  if (it != M2[i].end()) e = it->second - 1;
  if (it != M2[i].begin()) it--, s = it->second + 1;
  while (s < e) {
    long long int m = (s + e) / 2;
    if (query(i, m) < y)
      s = m + 1;
    else
      e = m;
  }
  return s;
}
int getMid(long long int m, int q, vector<int> v) {
  int t = 0;
  while (v.size() > 1) {
    t++;
    if (t > 50) break;
    random_shuffle(v.begin(), v.end());
    int i, p = 1;
    while ((1 << p) <= v.size()) p++;
    p /= 2, p = max(p, 4), p = min(p, (int)v.size());
    vector<pair<long long int, int> > vv;
    for (i = 0; i < p; i++) vv.push_back(make_pair(pos(v[i], m), v[i]));
    sort(vv.begin(), vv.end());
    vector<int> vvv[15];
    for (i = 0; i < vv.size(); i++) vvv[i].push_back(vv[i].second);
    for (i = p; i < v.size(); i++) {
      int ll = 0, rr = p;
      while (ll < rr) {
        int mm = (ll + rr) / 2;
        if (query(v[i], vv[mm].first) < m)
          ll = mm + 1;
        else
          rr = mm;
      }
      vvv[ll].push_back(v[i]);
    }
    int s = 0;
    for (i = 0; i < p + 1; i++) {
      s += vvv[i].size();
      if (s >= q) {
        s -= vvv[i].size();
        break;
      }
    }
    v = vvv[i], q -= s;
  }
  return v[0];
}
int findAns(long long int s, long long int e, long long int l, long long int r,
            vector<int> v) {
  if (v.size() == 1) {
    al[v[0]] = s, ar[v[0]] = e;
    return 0;
  }
  int i;
  vector<int> ll, mm, rr;
  long long int m = (l / (L / n) + r / (L / n)) / 2 * (L / n);
  int x = getMid(m, v.size() / 2, v);
  long long int y = pos(x, m);
  for (i = 0; i < v.size(); i++) {
    if (query(v[i], y) == m)
      mm.push_back(v[i]);
    else if (query(v[i], y) < m)
      rr.push_back(v[i]);
    else
      ll.push_back(v[i]);
  }
  while (!mm.empty()) {
    if (ll.size() >= rr.size())
      rr.push_back(mm.back());
    else
      ll.push_back(mm.back());
    mm.pop_back();
  }
  findAns(s, y, l, m, ll), findAns(y, e, m, r, rr);
  return 0;
}
int main() {
  int i;
  cin >> n >> L;
  vector<int> v;
  for (i = 0; i < n; i++) v.push_back(i);
  findAns(0, 1e18, 0, L, v);
  cout << "!" << endl;
  for (i = 0; i < n; i++) cout << al[i] << " " << ar[i] << endl;
  return 0;
}
