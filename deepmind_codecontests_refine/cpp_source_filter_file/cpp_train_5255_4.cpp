#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const int inf = 0x3f3f3f3f;
int w[maxn][maxn], e[maxn][maxn];
int gcd(int a, int b) { return b % a == 0 ? a : gcd(b % a, a); }
int a[maxn], b[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &w[i][j]);
  a[1] = 0;
  for (int i = 1; i <= m; i++) b[i] = w[1][i];
  for (int i = 1; i <= n; i++) a[i] = w[i][1] - b[1];
  int g = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      e[i][j] = abs(a[i] + b[j] - w[i][j]);
      if (e[i][j]) {
        if (!g)
          g = e[i][j];
        else
          g = max(g, gcd(e[i][j], g));
      }
    }
  if (!g) {
    printf("YES\n%d\n", inf);
    for (int i = 1; i <= n; i++) {
      if (a[i] < 0) a[i] += inf;
      printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    for (int i = 1; i <= m; i++) {
      if (b[i] < 0) b[i] += inf;
      printf("%d%c", b[i], i == m ? '\n' : ' ');
    }
  } else {
    bool ok = true;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (w[i][j] > g) ok = false;
    if (!ok)
      printf("NO\n");
    else {
      printf("YES\n%d\n", g);
      for (int i = 1; i <= n; i++) {
        if (a[i] < 0) a[i] = a[i] % g + g;
        printf("%d%c", a[i], i == n ? '\n' : ' ');
      }
      for (int i = 1; i <= m; i++) {
        if (b[i] < 0) b[i] = b[i] % g + g;
        printf("%d%c", b[i], i == m ? '\n' : ' ');
      }
    }
  }
  return 0;
}
