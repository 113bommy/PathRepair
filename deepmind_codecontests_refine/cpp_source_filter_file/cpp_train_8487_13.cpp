#include <bits/stdc++.h>
using namespace std;
long long Pow(long long a, long long b, long long MOD) {
  a %= MOD;
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    b /= 2;
    a = (a * a) % MOD;
  }
  return res;
}
const int maxn = 200000 + 10;
const int MOD = 1e9 + 7;
double dp[51][maxn];
long long sum[maxn];
double rev[maxn], E[maxn];
int t[maxn], st[maxn], top, tail;
double cost(int l, int r) {
  return E[r] - E[l - 1] - sum[l - 1] * (rev[r] - rev[l - 1]);
}
double G(int j, int k, int p) {
  double temp1 =
      dp[p][j] - E[j] + sum[j] * rev[j] - (dp[p][k] - E[k] + sum[k] * rev[k]);
  double temp2 = sum[j] - sum[k];
  return temp1 / temp2;
}
int solve(double revi, int k) {
  while (top < tail - 1 && G(st[top + 1], st[top], k) < revi) top++;
  return st[top];
}
int main() {
  int i, j, n, k;
  scanf("%d%d", &n, &k);
  sum[0] = 0;
  rev[0] = 0;
  E[0] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%d", &t[i]);
    sum[i] = sum[i - 1] + t[i];
    rev[i] = rev[i - 1] + 1.0 / t[i];
    E[i] = E[i - 1] + 1.0 * sum[i] / t[i];
  }
  double res = 0;
  for (i = 1; i <= n; i++) dp[1][i] = E[i];
  for (i = 2; i <= k; i++) {
    top = tail = 0;
    st[tail++] = 0;
    for (j = 1; j <= n; j++) {
      while (top < tail - 1 &&
             G(j, st[tail - 1], k - 1) < G(st[tail - 1], st[tail - 2], k - 1))
        tail--;
      st[tail++] = j;
    }
    for (j = 1; j <= n; j++) {
      if (j >= i) {
        int pos = solve(rev[j], k - 1);
        dp[i][j] = dp[i - 1][pos] + cost(pos + 1, j);
      } else
        dp[i][j] = 1e50;
    }
  }
  printf("%.10f\n", dp[k][n]);
  return 0;
}
