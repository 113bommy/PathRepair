#include <bits/stdc++.h>
using namespace std;
const int B = 172;
const int S = 44000;
const int D = 20;
unordered_map<bitset<B>, int> H;
bool A[D][S];
bitset<B> a[S];
int go[S][10];
int n;
int d[20];
long long dp[20][10][S];
long long solve(long long n, int k) {
  if (n == 0) return 1;
  int m = 0;
  while (n) d[m++] = n % 10, n /= 10;
  int u = 1;
  long long ret = 0;
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < d[i] + (i == 0); j++) ret += dp[i][k][go[u][j]];
    u = go[u][d[i]];
  }
  return ret;
}
int main() {
  bitset<B> cur;
  cur.set(0);
  H[cur] = 1;
  a[1] = cur;
  A[0][1] = 1;
  n = 1;
  for (int i = 1; i < D; i++) {
    for (int u = 1; u <= n; u++)
      if (A[i - 1][u]) {
        for (int j = 0; j < 10; j++) {
          if (!go[u][j]) {
            if (j == 0) {
              go[u][j] = u;
            } else {
              cur.reset();
              for (int k = j; k < B; k++)
                if (a[u][k]) cur[k - j] = 1;
              for (int k = 0; k < B - j; k++)
                if (a[u][k]) cur[k + j] = 1;
              for (int k = 1; k < j; k++)
                if (a[u][k]) cur[j - k] = 1;
              if (H.count(cur)) {
                go[u][j] = H[cur];
              } else {
                go[u][j] = H[cur] = ++n;
                a[n] = cur;
              }
            }
          }
          A[i][go[u][j]] = 1;
        }
      }
  }
  for (int j = 1; j <= n; j++) {
    int k = 0;
    for (k = 0; k < 10; k++)
      if (a[j][k]) break;
    for (; k < 10; k++) dp[0][k][j] = 1;
  }
  for (int j = 1; j < D - 1; j++) {
    for (int k = 1; k <= n; k++)
      if (A[D - 1 - j][k]) {
        for (int i = 0; i < 10; i++) {
          for (int l = 0; l < 10; l++) dp[j][l][k] += dp[j - 1][l][go[k][i]];
        }
      }
  }
  int ncase;
  for (scanf("%d", &ncase); ncase--;) {
    long long l, r;
    int k;
    scanf("%lld%lld%d", &l, &r, &k);
    printf("%lld\n", solve(r, k) - solve(l - 1, k));
  }
  return 0;
}
