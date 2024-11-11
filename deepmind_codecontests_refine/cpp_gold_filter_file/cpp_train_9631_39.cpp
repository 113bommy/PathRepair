#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char T[2][2005], S[2005];
int f[2][2005][2005];
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
int lhT[2][2005], rhT[2][2005], hS[2005], p[2005];
int lhsh(int t, int l, int r) {
  return (lhT[t][r] - 1ll * lhT[t][l - 1] * p[r - l + 1] % mod + mod) % mod;
}
int rhsh(int t, int l, int r) {
  return (rhT[t][l] - 1ll * rhT[t][r + 1] * p[r - l + 1] % mod + mod) % mod;
}
int Hsh(int l, int r) {
  return (hS[r] - 1ll * hS[l - 1] * p[r - l + 1] % mod + mod) % mod;
}
int main() {
  scanf("%s", T[0] + 1);
  scanf("%s", T[1] + 1);
  scanf("%s", S + 1);
  int n = strlen(T[0] + 1), l = strlen(S + 1);
  if (l == 1) {
    int ans = 0;
    for (int t = 0; t < 2; t++)
      for (int i = 1; i <= n; i++)
        if (T[t][i] == S[1]) ans++;
    printf("%d\n", ans);
    return 0;
  }
  if (l == 2) {
    int ans = 0;
    for (int t = 0; t < 2; t++)
      for (int i = 1; i < n; i++)
        if (T[t][i] == S[1] && T[t][i + 1] == S[2]) ans++;
    for (int t = 0; t < 2; t++)
      for (int i = 2; i <= n; i++)
        if (T[t][i] == S[1] && T[t][i - 1] == S[2]) ans++;
    for (int t = 0; t < 2; t++)
      for (int i = 1; i <= n; i++)
        if (T[t][i] == S[1] && T[t ^ 1][i] == S[2]) ans++;
    printf("%d\n", ans);
    return 0;
  }
  p[0] = 1;
  for (int i = 1; i <= 2000; i++) p[i] = p[i - 1] * 31ll % mod;
  for (int t = 0; t < 2; t++) {
    for (int i = 1; i <= n; i++)
      lhT[t][i] = (lhT[t][i - 1] * 31ll + T[t][i] - 'a' + 1) % mod;
    for (int i = n; i >= 1; i--)
      rhT[t][i] = (rhT[t][i + 1] * 31ll + T[t][i] - 'a' + 1) % mod;
  }
  for (int i = 1; i <= l; i++)
    hS[i] = (hS[i - 1] * 31ll + S[i] - 'a' + 1) % mod;
  f[0][0][0] = f[1][0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int t = 0; t < 2; t++) {
      f[t][i][0] = 1;
      for (int j = 0; j <= l; j++) {
        if (S[j + 1] == T[t][i]) add(f[t][i][j + 1], f[t][i - 1][j]);
        if (S[j + 1] == T[t ^ 1][i] && S[j + 2] == T[t][i])
          add(f[t][i][j + 2], f[t ^ 1][i - 1][j]);
      }
      for (int j = 1; j < i; j++) {
        int x = i - j + 1;
        if (x * 2 > l) continue;
        if (rhsh(t ^ 1, j, i) == Hsh(1, x) &&
            lhsh(t, j, i) == Hsh(x + 1, 2 * x))
          add(f[t][i][2 * x], 1);
      }
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int t = 0; t < 2; t++) {
      add(ans, f[t][i][l]);
      for (int j = i + 1; j <= n; j++) {
        int x = j - i + 1;
        if (2 * x >= l) break;
        if (rhsh(t ^ 1, i, j) == Hsh(l - x + 1, l) &&
            lhsh(t, i, j) == Hsh(l - 2 * x + 1, l - x)) {
          add(ans, f[t][i - 1][l - 2 * x]);
        }
      }
    }
  for (int i = 1; i <= l; i++)
    if (i < l - i + 1) swap(S[i], S[l - i + 1]);
  for (int i = 1; i <= l; i++)
    hS[i] = (hS[i - 1] * 31ll + S[i] - 'a' + 1) % mod;
  memset(f, 0, sizeof(f));
  f[0][0][0] = f[1][0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int t = 0; t < 2; t++) {
      f[t][i][0] = 1;
      for (int j = 0; j <= l; j++) {
        if (S[j + 1] == T[t][i]) add(f[t][i][j + 1], f[t][i - 1][j]);
        if (S[j + 1] == T[t ^ 1][i] && S[j + 2] == T[t][i])
          add(f[t][i][j + 2], f[t ^ 1][i - 1][j]);
      }
      for (int j = 1; j < i; j++) {
        int x = i - j + 1;
        if (2 * x >= l) continue;
        if (rhsh(t ^ 1, j, i) == Hsh(1, x) &&
            lhsh(t, j, i) == Hsh(x + 1, 2 * x))
          add(f[t][i][2 * x], 1);
      }
    }
  for (int i = 1; i <= n; i++)
    for (int t = 0; t < 2; t++) {
      add(ans, f[t][i][l]);
      for (int j = i + 1; j <= n; j++) {
        int x = j - i + 1;
        if (2 * x > l) break;
        if (rhsh(t ^ 1, i, j) == Hsh(l - x + 1, l) &&
            lhsh(t, i, j) == Hsh(l - 2 * x + 1, l - x)) {
          add(ans, f[t][i - 1][l - 2 * x]);
        }
      }
    }
  printf("%d\n", ans);
  return 0;
}
