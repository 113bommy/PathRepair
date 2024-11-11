#include <bits/stdc++.h>
using namespace std;
const int N = 4010, K = 810;
int n, k, a[N][N];
int f[K][N];
int opt[K][N];
void enter() {
  char buffer[N * 10];
  scanf("%d %d\n", &n, &k);
  for (int i = (1), _b = (n); i <= _b; ++i) {
    gets(buffer + 1);
    for (int j = (1), _b = (n); j <= _b; ++j) {
      a[i][j] = buffer[j * 2 - 1] - '0';
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
}
int cost(int i, int j) {
  return a[j][j] - a[i - 1][j] - a[j][i - 1] + a[i - 1][i - 1];
}
void solve(int k, int l, int r, int optL, int optR) {
  if (l > r) return;
  int m = (l + r) / 2;
  f[k][m] = 1E9;
  for (int i = max(optL, k - 1); i <= min(optR, m - 1); ++i) {
    if (f[k][m] > f[k - 1][i] + cost(i + 1, m)) {
      f[k][m] = f[k - 1][i] + cost(i + 1, m);
      opt[k][m] = i;
    }
  }
  solve(k, l, m - 1, optL, opt[k][m]);
  solve(k, m + 1, r, opt[k][m], optR);
}
int main() {
  enter();
  for (int i = (1), _b = (n); i <= _b; ++i) f[0][i] = 1E18;
  for (int layer = (1), _b = (k); layer <= _b; ++layer)
    solve(layer, 1, n, 0, n - 1);
  cout << f[k][n] / 2;
}
