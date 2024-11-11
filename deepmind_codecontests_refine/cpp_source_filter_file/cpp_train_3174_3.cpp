#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
const long long MX = 1e5 + 7;
const long long INF = 1e9;
vector<pair<long long, long long> > t[4 * MX];
vector<long long> suf_min[4 * MX];
vector<long long> bl, br;
void build(long long v, long long tl, long long tr) {
  if (tl == tr) {
    t[v].push_back({-bl[tl], tl});
  } else {
    long long tm = (tl + tr) >> 1;
    build(v << 1, tl, tm);
    build((v << 1) | 1, tm + 1, tr);
    for (pair<long long, long long> i : t[v << 1]) t[v].push_back(i);
    for (pair<long long, long long> i : t[(v << 1) | 1]) t[v].push_back(i);
  }
  sort(t[v].begin(), t[v].end());
  suf_min[v].resize(t[v].size());
  suf_min[v].push_back(INF);
  for (long long i = (long long)t[v].size() - 1; i >= 0; i--) {
    suf_min[v][i] = min(suf_min[v][i + 1], t[v][i].second);
  }
}
long long get(long long v, long long tl, long long tr, long long l, long long r,
              long long val) {
  if (l > r) return INF;
  if (tl == l && tr == r) {
    long long l1 = -1, r1 = t[v].size();
    while (r1 - l1 > 1) {
      long long m = (l1 + r1) >> 1;
      if (t[v][m].first >= val)
        r1 = m;
      else
        l1 = m;
    }
    return suf_min[v][r1];
  }
  long long tm = (tl + tr) >> 1;
  return min(get(v << 1, tl, tm, l, min(r, tm), val),
             get((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r, val));
}
int main() {
  iostream::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> c(n + 2), l(n + 2), r(n + 2);
  for (long long i = 0; i < n + 2; i++) {
    cin >> c[i];
    if (i && i < n + 1) {
      l[i] = i - 1;
      r[i] = i + 1;
    }
  }
  vector<long long> d(n + 2);
  for (long long i = 0; i < n; i++) {
    cin >> d[i + 1];
    d[i + 1] *= 2;
  }
  bl.resize(n + 2, 1e9 + 1);
  br.resize(n + 2, -1);
  queue<long long> q;
  long long cn = 0;
  auto _l = l, _r = r;
  auto iter = [&](long long bg, long long en) {
    while (!q.empty()) {
      long long v = q.front();
      q.pop();
      cn++;
      r[l[v]] = r[v];
      if (l[v] >= bg) {
        if (c[r[l[v]]] - c[l[l[v]]] > d[l[v]]) {
          q.push(l[v]);
        }
      }
      l[r[v]] = l[v];
      if (r[v] <= en) {
        if (c[r[r[v]]] - c[l[r[v]]] > d[r[v]]) {
          q.push(r[v]);
        }
      }
    }
  };
  for (long long i = 1; i <= n; i++) {
    long long mx = d[i] - (c[i] - c[l[i]]);
    if (mx <= 0) {
      br[i] = -1;
    } else {
      br[i] = c[i] + mx;
    }
    if (c[r[i]] - c[l[i]] > d[i]) {
      q.push(i);
    }
    iter(1, i);
  }
  if (cn < n) {
    cout << 0;
    return 0;
  }
  l = _l;
  r = _r;
  for (long long i = n; i >= 1; i--) {
    long long mx = d[i] - (c[r[i]] - c[i]);
    if (mx <= 0) {
      bl[i] = 1e9 + 1;
    } else {
      bl[i] = c[i] - mx;
    }
    if (c[r[i]] - c[l[i]] > d[i]) {
      q.push(i);
    }
    iter(i, n);
  }
  br[0] = c[n - 1];
  bl[n + 1] = 0;
  build(1, 0, n + 1);
  long long ans = c[n + 1] - c[0];
  for (long long i = 0; i < n + 1; i++) {
    if (br[i] == -1) {
      continue;
    }
    long long pos = br[i];
    long long j = get(1, 0, n + 1, i + 1, n + 1, -pos);
    if (j != INF) {
      ans = min(ans, c[j] - c[i]);
    }
  }
  cout << ans / 2 << '.' << (ans % 2) * 5 << '\n';
  return 0;
}
