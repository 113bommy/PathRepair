#include <bits/stdc++.h>
using namespace std;
template <class T, class L>
bool smax(T &x, L y) {
  return x < y ? (x = y, 1) : 0;
}
template <class T, class L>
bool smin(T &x, L y) {
  return y < x ? (x = y, 1) : 0;
}
const int maxn = 2e3 + 17, mod = 1e9 + 7;
int n, m, mon[maxn][maxn], ps[maxn], ans;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  fill(mon[1], mon[2], 1);
  for (int h = 2; h < maxn; h++) {
    partial_sum(mon[h - 1], mon[h], ps,
                [](const int &x, const int &y) { return (x + y) % mod; });
    for (int w = 0; w < maxn; w++)
      mon[h][w] = (ps[w] + (w ? mon[h][w - 1] : 0)) % mod;
  }
  for (int h = 2; h < maxn; h++)
    for (int w = 0; w < maxn; w++) (mon[h][w] += mon[h - 1][w]) %= mod;
  for (int row = 0; row < n; row++)
    for (int len = 0; len <= m - 2; len++)
      (ans += (long long)(mon[row + 1][len] - mon[row][len]) *
              mon[n - row][len] % mod * (m - 1 - len) % mod) %= mod;
  cout << ans << '\n';
  return 0;
}
