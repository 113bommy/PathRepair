#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
double eps = 1e-8;
long long INF = 1e14;
char ch[510000];
int a[510000], b[510000], c[510000];
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
int main() {
  int q = read();
  while (q--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = (int)1; i <= (int)n; i++) a[i] = 0;
    for (int i = (int)1; i <= (int)m; i++) b[i] = 0;
    for (int i = (int)1; i <= (int)n; i++)
      for (int j = (int)1; j <= (int)m; j++) c[(i - 1) * n + j] = 0;
    for (int i = (int)1; i <= (int)n; i++) {
      scanf("%s", ch + 1);
      for (int j = (int)1; j <= (int)m; j++)
        if (ch[j] == '.') {
          a[i]++;
          b[j]++;
          c[(i - 1) * m + j] = 1;
        }
    }
    int ans = n + m - 1;
    for (int i = (int)1; i <= (int)n; i++)
      for (int j = (int)1; j <= (int)m; j++)
        if (c[(i - 1) * m + j] == 1)
          ans = min(ans, a[i] + b[j] - 1);
        else
          ans = min(ans, a[i] + b[j]);
    printf("%d\n", ans);
  }
  return 0;
}
