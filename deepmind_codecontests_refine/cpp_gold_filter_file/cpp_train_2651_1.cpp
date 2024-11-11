#include <bits/stdc++.h>
using namespace std;
inline int Get() {
  int res = 0, q = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') q = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return res * q;
}
const double eps = 1e-12, pi = M_PI;
const int oo = (int)2e9, mod = (int)1e9 + 7;
const long long INF = (long long)1e17;
const int N = (int)1e6;
int n, m, K, d;
char s[2][N + 10];
int f[N + 10][22];
int main() {
  scanf("%s", s[0]), n = strlen(s[0]);
  int cur = 0;
  scanf(
      "%d"
      "\n",
      &m);
  for (; m--;) {
    scanf(
        "%d"
        "%d"
        "\n",
        &K, &d);
    cur ^= 1;
    int tot = 0;
    for (int i = (0), end = (d - 1); i <= end; ++i) {
      f[i][0] = tot++;
      for (int j = i + d; j < K; j += d) f[j][0] = f[j - d][0] + 1, ++tot;
    }
    for (int i = (1), end = (20); i <= end; ++i) {
      int to = 1 << (i - 1);
      if (to > n) break;
      for (int j = (0), end = (K - 1); j <= end; ++j) {
        int k = f[j][i - 1];
        if (k <= to)
          f[j][i] = k;
        else
          f[j][i] = f[k - to][i - 1] + to;
      }
    }
    int u = K - 1;
    for (int i = (0), end = (n - 1); i <= end; ++i) {
      int tot = 0, now = min(i, u), ed = min(n - i, n - K + 1);
      for (int j = (20), end = (0); j >= end; --j)
        if (tot + (1 << j) <= ed) {
          if (now <= tot) break;
          now = tot + f[now - tot][j], tot += (1 << j);
        }
      now += max(0, i - u);
      s[cur][now] = s[cur ^ 1][i];
    }
    for (int i = (0), end = (n - 1); i <= end; ++i) printf("%c", s[cur][i]);
    printf("\n");
  }
  return 0;
}
