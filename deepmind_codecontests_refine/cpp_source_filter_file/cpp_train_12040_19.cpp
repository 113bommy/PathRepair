#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000001;
int n, dp[maxn], F[11][maxn];
int f(int n) {
  int res = 1;
  while (n) {
    if (n % 10) res *= n % 10;
    n /= 10;
  }
  return res;
}
int g(int x) {
  if (x < 10) return x;
  if (dp[x]) return dp[x];
  return dp[x] = g(f(x));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  F[1][1] = 1;
  for (int i = 2; i <= maxn; ++i) {
    F[g(i)][i] = 1;
    for (int k = 1; k < 10; ++k) F[k][i] += F[k][i - 1];
  }
  int l, r, q, k;
  cin >> q;
  while (cin >> l >> r >> k, q--) cout << F[k][r] - F[k][l - 1] << '\n';
}
