#include <bits/stdc++.h>
using namespace std;
const int N = 2020;
const long long mod = 998244353;
const long long g = 3;
const double eps = 1e-8;
template <class T>
void Mul(T &x, T y) {
  x = x * y % mod;
}
template <class T>
void Add(T &x, T y) {
  x = (x + y) % mod;
}
template <class T>
void Sub(T &x, T y) {
  x = (x - y + mod) % mod;
}
template <class T>
void Mn(T &x, T y) {
  x = min(x, y);
}
template <class T>
void Mx(T &x, T y) {
  x = max(x, y);
}
long long qpow(long long x, long long y = mod - 2) {
  long long res = 1;
  while (y) {
    if (y & 1) Mul(res, x);
    Mul(x, x), y >>= 1;
  }
  return res;
}
void Div(long long &x, long long y) { Mul(x, qpow(y)); }
int n, m, k, T, tax[N * N], tnum = 0;
pair<int, int> a[N], b[N];
pair<int, int> lim[N];
priority_queue<pair<int, int> > pq;
int calc(int v) {
  int res = 0;
  return res;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  for (int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (b[j].first >= a[i].first && b[j].second >= a[i].second) {
        pq.push(pair<int, int>(b[j].second - a[i].second + 1,
                               b[j].first - a[i].first + 1));
        tax[++tnum] = b[j].first - a[i].first + 1;
      }
    }
  }
  int ans = 1e9;
  sort(tax + 1, tax + tnum + 1);
  tnum = unique(tax + 1, tax + tnum + 1) - tax - 1;
  if (!pq.empty()) Mn(ans, pq.top().first);
  for (int i = 1, nw; i <= tnum; i++) {
    nw = tax[i];
    while (!pq.empty() && pq.top().second <= nw) pq.pop();
    if (!pq.empty())
      Mn(ans, nw + pq.top().first);
    else
      Mn(ans, nw);
  }
  cout << ans << '\n';
}
