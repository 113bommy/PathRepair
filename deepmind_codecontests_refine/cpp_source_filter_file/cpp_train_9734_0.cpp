#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 400, md = 1e9 + 7;
int p, alpha, n, num[N], len = 0, tmp[N], pum[N], plen = 0;
int dp[N][N][2][2];
char numb[N];
int add(int x) { return x >= md ? x - md : x; }
int sub(int x) { return x < 0 ? x + md : x; }
int divide() {
  for (int i = 0; i <= len; i++) tmp[i] = 0;
  int dg = 0;
  for (int i = len; i >= 0; i--) {
    dg = dg * 10 + num[i];
    tmp[i] += dg / p;
    dg %= p;
  }
  while (tmp[len] == 0 && len >= 0) len--;
  for (int i = 0; i <= len; i++) num[i] = tmp[i];
  return dg;
}
void transP() {
  scanf("%s", numb);
  n = strlen(numb);
  for (int i = 0; i < n; i++) num[i] = numb[n - i - 1] - '0';
  len = n - 1;
  while (len >= 0) {
    pum[plen] = divide();
    plen++;
  }
  len = plen - 1;
  return;
}
int S(int x) {
  if (x > 2 * p - 2) return 1ll * p * p % md;
  if (x < 0) return 0;
  if (x < p) return 1ll * (x + 2) * (x + 1) / 2 % md;
  x = 2 * (p - 1) - x - 1;
  return sub(1ll * p * p % md - 1ll * (x + 2) * (x + 1) / 2 % md);
}
int DP(int pos, int c, int l, int pl) {
  if (c < 0) return 0;
  if (pos == -1) {
    if (c > 0 || pl) return 0;
    return 1;
  }
  int &res = dp[pos][c][l][pl];
  if (res != -1) return res;
  res = 0;
  int R = l ? pum[pos] : p - 1, L = 0;
  R += p * pl;
  L += p * pl;
  for (int npl = 0; npl <= 1; npl++) {
    res = add(res + 1ll * DP(pos - 1, c - pl, 0, npl) *
                        sub(S(R - 1 - npl) - S(L - 1 - npl)) % md);
    res = add(res + 1ll * DP(pos - 1, c - pl, l, npl) *
                        sub(S(R - npl) - S(R - 1 - npl)) % md);
  }
  return res;
}
int main() {
  scanf("%d%d", &p, &alpha);
  transP();
  for (int i = 0; i <= len; i++)
    for (int j = 0; j <= len + 1; j++)
      dp[i][j][0][0] = dp[i][j][0][1] = dp[i][j][1][0] = dp[i][j][1][1] = -1;
  int res = 0;
  for (int i = alpha; i <= len + 1; i++) res = (res + DP(len, i, 1, 0)) % md;
  printf("%d\n", res);
  return 0;
}
