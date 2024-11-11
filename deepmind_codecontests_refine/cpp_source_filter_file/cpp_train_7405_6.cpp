#include <bits/stdc++.h>
using namespace std;
const int N = 110000;
const int MOD = 1e9 + 7;
int f(char c) {
  if (isupper(c))
    return c - 'A' + 27;
  else
    return c - 'a' + 1;
}
void add(int &x, int y) { (x += y) >= MOD && (x -= MOD); }
int L[55][N], R[55][N], ans[55][55], r[N], cn[55];
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> s;
  int n = s.length();
  for (int i = 0; i < n; i++) cn[f(s[i])]++;
  for (int i = 1; i <= 52; i++) {
    memset(L, 0, sizeof L);
    memset(R, 0, sizeof R);
    L[0][0] = 1;
    for (int j = 1; j <= 52; j++) {
      int x = cn[j];
      if (j == i) x = 0;
      for (int k = 0; k <= n; k++) {
        L[j][k] = L[j - 1][k];
        if (k >= x && x) add(L[j][k], L[j - 1][k - x]);
      }
    }
    R[53][0] = 1;
    for (int j = 52; j >= 1; j--) {
      int x = cn[j];
      if (j == i) x = 0;
      for (int k = 0; k <= n; k++) {
        R[j][k] = R[j + 1][k];
        if (k >= x && x) add(R[j][j], R[j + 1][k - x]);
      }
    }
    for (int j = 1; j <= 52; j++) {
      for (int k = 0; k <= n / 2; k++)
        ans[i][j] = (ans[i][j] + 1LL * L[j - 1][k] * R[j + 1][n / 2 - k]) % MOD;
    }
  }
  for (int i = 1; i <= n; i++)
    r[i] = (i == 1 ? 1 : r[MOD % i] * 1LL * (MOD - MOD / i) % MOD);
  int all = 1;
  for (int j = 1; j <= 2; j++)
    for (int i = 1; i <= n / 2; i++) all = 1LL * all * i % MOD;
  for (int i = 1; i <= 52; i++) {
    for (int j = 1; j <= cn[i]; j++) all = 1LL * all * r[j] % MOD;
  }
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << 2LL * ans[f(s[a - 1])][f(s[b - 1])] * all % MOD << '\n';
  }
  return 0;
}
