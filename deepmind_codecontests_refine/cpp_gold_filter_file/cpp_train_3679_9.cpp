#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
const int mod = 1000000007;
int f[30], n, m, k, len, A, B, AA, AB, BA;
char s[30][maxn], t[maxn];
long long K;
int tmp[2][2], res[2][2], bin[2][2];
void mul(int a[2][2], int b[2][2], int c[2][2]) {
  for (int i = (0); i <= (1); i++)
    for (int j = (0); j <= (1); j++) {
      tmp[i][j] = 0;
      for (int k = (0); k <= (1); k++)
        tmp[i][j] = (tmp[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
    }
  for (int i = (0); i <= (1); i++)
    for (int j = (0); j <= (1); j++) c[i][j] = tmp[i][j];
}
void power(int a[2][2], long long p) {
  for (int i = (0); i <= (1); i++)
    for (int j = (0); j <= (1); j++) res[i][j] = (i == j), bin[i][j] = a[i][j];
  while (p) {
    if (p & 1) mul(res, bin, res);
    mul(bin, bin, bin);
    p >>= 1;
  }
  for (int i = (0); i <= (1); i++)
    for (int j = (0); j <= (1); j++) a[i][j] = res[i][j];
}
int MA[2][2], MB[2][2];
int getfib(long long k) {
  MB[0][0] = MB[1][0] = MB[0][1] = 1;
  MB[1][1] = 0;
  MA[0][0] = 1;
  MA[1][0] = 0;
  power(MB, k - 1);
  mul(MB, MA, MA);
  return MA[0][0];
}
int nxt[maxn];
int calc(char s[maxn], int ls, char t[maxn], int lt) {
  int k, res = 0;
  nxt[1] = k = 1;
  res = 0;
  for (int i = (2); i <= (ls); i++) {
    while (k >= 2 && s[i] != s[k]) k = nxt[k - 1];
    if (s[i] == s[k]) k++;
    nxt[i] = k;
  }
  k = 1;
  for (int i = (1); i <= (lt); i++) {
    while (k >= 2 && t[i] != s[k]) k = nxt[k - 1];
    if (t[i] == s[k]) k++;
    if (k == ls + 1) res++, k = nxt[k - 1];
  }
  return res;
}
int flag[maxn];
char revB[maxn], revt[maxn];
int solve(char A[maxn], int lA, char B[maxn], int lB, char t[maxn], int lt) {
  for (int i = (1); i <= (lt - 1); i++) flag[i] = 0;
  for (int i = (1); i <= (lB); i++) revB[i] = B[lB + 1 - i];
  for (int i = (1); i <= (lt); i++) revt[i] = t[lt + 1 - i];
  int k;
  nxt[1] = k = 1;
  for (int i = (2); i <= (lt); i++) {
    while (k >= 2 && t[i] != t[k]) k = nxt[k - 1];
    if (t[i] == t[k]) k++;
    nxt[i] = k;
  }
  k = 1;
  for (int i = (1); i <= (lA); i++) {
    while (k >= 2 && A[i] != t[k]) k = nxt[k - 1];
    if (A[i] == t[k]) k++;
    if (k == lt + 1) k = nxt[k - 1];
  }
  while (k >= 2) {
    flag[lt - (k - 1)]++;
    k = nxt[k - 1];
  }
  nxt[1] = k = 1;
  for (int i = (2); i <= (lt); i++) {
    while (k >= 2 && revt[i] != revt[k]) k = nxt[k - 1];
    if (revt[i] == revt[k]) k++;
    nxt[i] = k;
  }
  k = 1;
  for (int i = (1); i <= (lB); i++) {
    while (k >= 2 && revB[i] != revt[k]) k = nxt[k - 1];
    if (revB[i] == revt[k]) k++;
    if (k == lt + 1) k = nxt[k - 1];
  }
  while (k >= 2) {
    flag[k - 1]++;
    k = nxt[k - 1];
  }
  int res = 0;
  for (int i = (1); i <= (lt - 1); i++)
    if (flag[i] == 2) res++;
  return res;
}
int main() {
  f[1] = f[m = 2] = 1;
  while (f[m - 1] < 100000) {
    f[m + 1] = f[m] + f[m - 1];
    m++;
  }
  s[1][1] = 'a';
  s[2][1] = 'b';
  for (int i = (3); i <= (m); i++) {
    for (int j = (1); j <= (f[i - 1]); j++) s[i][j] = s[i - 1][j];
    for (int j = (1); j <= (f[i - 2]); j++) s[i][j + f[i - 1]] = s[i - 2][j];
  }
  cin >> K >> n;
  while (n--) {
    scanf("%s", t + 1);
    len = strlen(t + 1);
    k = 1;
    while (f[k] < len) k++;
    if (K < k) {
      puts("0");
      continue;
    }
    if (K == k) {
      printf("%d\n", calc(t, len, s[k], f[k]));
      continue;
    }
    if (K == k + 1) {
      printf("%d\n", calc(t, len, s[k + 1], f[k + 1]));
      continue;
    }
    A = calc(t, len, s[k + 1], f[k + 1]);
    B = calc(t, len, s[k], f[k]);
    AA = solve(s[k + 1], f[k + 1], s[k + 1], f[k + 1], t, len);
    AB = solve(s[k + 1], f[k + 1], s[k], f[k], t, len);
    BA = solve(s[k], f[k], s[k + 1], f[k + 1], t, len);
    int f0 = getfib(K - k), f1 = getfib(K - k - 1);
    int ans = (1ll * f0 * A + 1ll * f1 * B) % mod;
    if ((K - k) & 1) {
      ans = (ans + 1ll * f1 * AB) % mod;
      ans = (ans + 1ll * f1 * BA) % mod;
      ans = (ans + 1ll * (f0 - f1 + mod - 1) * AA) % mod;
    } else {
      ans = (ans + 1ll * f1 * AB) % mod;
      ans = (ans + 1ll * (f1 + mod - 1) * BA) % mod;
      ans = (ans + 1ll * (f0 - f1 + mod) * AA) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
