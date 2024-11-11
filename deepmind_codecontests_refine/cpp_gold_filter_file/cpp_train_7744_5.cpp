#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, k, a[4004][4004], d[808][4004];
inline int cost(int l, int r) {
  return a[r][r] - a[l - 1][r] - a[r][l - 1] + a[l - 1][l - 1];
}
void sol(int i, int l, int r, int u, int v) {
  if (l > r) return;
  if (l == r) {
    d[i][l] = mod;
    for (int j = u; j <= v; j++)
      d[i][l] = min(d[i][l], d[i - 1][j] + cost(j + 1, l));
    return;
  }
  int m = (l + r) / 2, o = -1;
  d[i][m] = mod;
  for (int j = u; j <= v; j++) {
    if (d[i][m] > d[i - 1][j] + cost(j + 1, m)) {
      d[i][m] = d[i - 1][j] + cost(j + 1, m);
      o = j;
    }
  }
  sol(i, l, m - 1, u, o);
  sol(i, m + 1, r, o, v);
}
void fastscan(int &number) {
  bool negative = false;
  int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fastscan(n);
  fastscan(k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) fastscan(a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
  for (int i = 1; i <= n; i++) d[0][i] = mod;
  for (int i = 1; i <= k; i++) sol(i, 1, n, 0, n - 1);
  cout << d[k][n] / 2 << '\n';
}
