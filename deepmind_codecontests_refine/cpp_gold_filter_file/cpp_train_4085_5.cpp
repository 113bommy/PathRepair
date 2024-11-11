#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string itos(int n) {
  stringstream ss;
  ss << n;
  string second = ss.str();
  return second;
}
long long ppow(long long x, long long y, long long mod) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}
const int N = 1e6 + 5;
const long long inf = 1e18;
long long t[4 * N], p[4 * N], best[N];
void push(int v) {
  int vv = v << 1;
  t[vv] += p[v];
  t[vv + 1] += p[v];
  p[vv] += p[v];
  p[vv + 1] += p[v];
  p[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, long long val) {
  if (r < tl || tr < l) return;
  if (l <= tl && tr <= r) {
    t[v] += val;
    p[v] += val;
    return;
  }
  int vv = v << 1;
  int tm = tl + tr >> 1;
  push(v);
  upd(vv, tl, tm, l, r, val);
  upd(vv + 1, tm + 1, tr, l, r, val);
  t[v] = min(t[vv], t[vv + 1]);
}
struct monst {
  long long x, y, z;
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 0; i < N; ++i) {
    best[i] = inf;
  }
  vector<pair<long long, long long>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < m; ++i) {
    long long b, cb;
    cin >> b >> cb;
    best[b] = min(best[b], cb);
  }
  vector<monst> c(p);
  for (int i = 0; i < p; ++i) {
    cin >> c[i].x >> c[i].y >> c[i].z;
  }
  for (int i = 0; i < N; ++i) {
    upd(1, 0, N - 1, i, i, best[i]);
  }
  vector<pair<pair<long long, long long>, long long>> check;
  for (int i = 0; i < n; ++i) {
    check.push_back({{a[i].first, 0}, i});
  }
  for (int i = 0; i < p; ++i) {
    check.push_back({{c[i].x, 1}, i});
  }
  long long ans = inf;
  sort(check.begin(), check.end());
  for (auto x : check) {
    int id = x.first.second, ind = x.second;
    if (!id) {
      ans = min(ans, a[ind].second + t[1]);
    } else {
      upd(1, 0, N - 1, c[ind].y + 1, N - 1, -c[ind].z);
    }
  }
  cout << -ans;
}
