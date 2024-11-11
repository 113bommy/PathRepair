#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, k, tt, ans[N];
bool f[N][N * N];
void solve(int l, int r, int k, bool op) {
  if (l == r) {
    ans[l] = ++tt;
    return;
  }
  int n = r - l + 1;
  for (int i = 4; n - i + 1 > 0; i++)
    if (f[n - i + 1][k - i]) {
      for (int j = r - i + 2; j <= r; j += 2) ans[j] = ++tt;
      solve(l, r - i + 1, k - i, 0);
      for (int j = r - i + 3; j <= r; j += 2) ans[j] = ++tt;
      if (i & 1) swap(ans[r], ans[r - 2]);
      return;
    }
  for (int i = 2; n - i + 1 > 0; i++)
    if (f[n - i + 1][k - i * (i + 1) / 2 + 1]) {
      if (!op) {
        solve(l, r - i + 1, k - i * (i + 1) / 2 + 1, 1);
        for (int j = r - i + 2; j <= r; j++) ans[j] = ++tt;
      } else {
        solve(l + i - 1, r, k - i * (i + 1) / 2 + 1, 0);
        for (int j = l + i - 2; j >= l; j--) ans[j] = ++tt;
      }
      return;
    }
  assert(!"gzyakioi2020");
}
int main() {
  f[1][1] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 0; j <= i * (i + 1) / 2; j++)
      if (f[i][j]) {
        for (int k = 4; i + k - 1 < N; k++) f[i + k - 1][j + k] = 1;
        for (int k = 2; i + k - 1 < N; k++)
          f[i + k - 1][j + k * (k + 1) / 2 - 1] = 1;
      }
  int T = gi();
  while (T--) {
    cin >> n >> k;
    tt = 0;
    if (!f[n][k])
      puts("NO");
    else {
      puts("YES");
      solve(1, n, k, 0);
      for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
      cout << '\n';
    }
  }
  return 0;
}
