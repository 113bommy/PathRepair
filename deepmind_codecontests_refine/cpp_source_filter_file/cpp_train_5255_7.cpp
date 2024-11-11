#include <bits/stdc++.h>
using namespace std;
int n, m, s[105][105], g = 0;
int lis[105], r[105], c[105];
int gcd(int a, int b) {
  if (b)
    return gcd(b, a % b);
  else
    return a;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &s[i][j]);
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) lis[j] = s[i][j] - s[1][j];
    for (int j = 2; j <= m; j++) g = gcd(g, lis[j] - lis[j - 1]);
  }
  for (int j = 2; j <= m; j++) {
    for (int i = 1; i <= n; i++) lis[i] = s[i][j] - s[i][1];
    for (int i = 2; i <= n; i++) g = gcd(g, lis[i] - lis[i - 1]);
  }
  g = abs(g);
  if (g == 0) {
    printf("YES\n1000000007\n");
    int mx = 1, my = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) {
        if (s[i][j] < s[mx][my]) mx = i, my = j;
      }
    for (int i = 1; i <= n; i++)
      printf("%d%c", s[i][my] - s[mx][my], i == n ? '\n' : ' ');
    for (int i = 1; i <= m; i++) printf("%d%c", s[mx][i], i == m ? '\n' : ' ');
  } else {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i][j] >= g) {
          printf("NO\n");
          return 0;
        }
      }
    }
    printf("YES\n%d\n", g);
    for (int i = 1; i <= n; i++)
      printf("%d%c", (0LL + s[i][1] - s[1][1] + g + g) % g,
             i == n ? '\n' : ' ');
    for (int i = 1; i <= m; i++) printf("%d%c", s[1][i], i == n ? '\n' : ' ');
  }
  return 0;
}
