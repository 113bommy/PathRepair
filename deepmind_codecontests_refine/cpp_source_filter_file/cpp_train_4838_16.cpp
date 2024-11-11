#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int mod = 1e9 + 7;
char s[maxn];
char t[maxn];
int f[maxn];
int w[maxn];
int dp[maxn];
int q[maxn];
int r[maxn];
int dp2[maxn];
int dp3[maxn];
void getFail(char *P, int *f) {
  int m = strlen(P);
  f[0] = 0;
  f[1] = 0;
  for (int i = 1; i < m; i++) {
    int j = f[i];
    while (j && P[i] != P[j]) {
      j = f[j];
    }
    f[i + 1] = P[i] == P[j] ? j + 1 : 0;
  }
}
void find(char *T, char *P, int *f) {
  int n = strlen(T);
  int m = strlen(P);
  getFail(P, f);
  int j = 0;
  int kk = -1;
  for (int i = 0; i < n; i++) {
    while (j && P[j] != T[i]) {
      j = f[j];
    }
    if (P[j] == T[i]) {
      j++;
    }
    if (j == m) {
      w[i - m + 1] = 1;
      q[i] = 1;
      r[i] = kk;
      kk = i - m + 1;
    }
  }
}
int main() {
  while (scanf("%s%s", s, t) != EOF) {
    int i;
    memset(w, 0, sizeof(w));
    memset(q, 0, sizeof(q));
    find(s, t, f);
    int n = strlen(s);
    int m = strlen(t);
    for (i = 0; i < n; i++) {
      if (q[i]) {
        dp[i] = i - m + 2;
        dp2[i] = i - m + 2;
        dp3[i] = i - m + 2;
        break;
      } else {
        dp[i] = 0;
        dp2[i] = 0;
        dp3[i] = 0;
      }
    }
    i++;
    for (; i < n; i++) {
      if (q[i] == 0) {
        dp[i] = dp[i - 1];
        dp2[i] = (dp[i] + dp2[i - 1]) % mod;
        dp3[i] = (dp2[i] + dp3[i - 1]) % mod;
      } else {
        dp[i] = (dp3[i - m] + i - m + 1) % mod;
        dp2[i] = (dp[i] + dp2[i - 1]) % mod;
        dp3[i] = (dp2[i] + dp3[i - 1]) % mod;
      }
    }
    printf("%d\n", dp2[n - 1]);
  }
  return 0;
}
