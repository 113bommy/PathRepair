#include <bits/stdc++.h>
using namespace std;
int n;
int s[10], g[15][5], w[10], l[10000], a[20], m[15][5];
char ch[20];
void pre() {
  s[1] = 2;
  s[2] = 3;
  s[3] = 5;
  s[4] = 7;
  for (int i = 2; i <= 9; ++i) {
    int k = i;
    for (int j = 1; j <= 4; ++j)
      if (k % s[j] == 0) {
        while (k % s[j] == 0 && k) {
          ++m[i][j];
          k /= s[j];
        }
      }
  }
  for (int i = 2; i <= 9; ++i) {
    for (int j = 1; j <= 4; ++j) g[i][j] = g[i - 1][j] + m[i][j];
  }
}
void init() {
  scanf("%d", &n);
  scanf("%s", ch);
  for (int i = 0; i < n; ++i) a[i + 1] = ch[i] - '0';
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= 4; ++j) w[j] += g[a[i]][j];
  for (int i = 4; i >= 1; --i)
    if (w[i]) {
      for (int j = 1; j < i; ++j) w[j] = w[j] - w[i] * g[s[i]][j];
      for (int j = 1; j <= w[i]; ++j) l[++l[0]] = s[i];
    }
  for (int i = 1; i <= l[0]; ++i) printf("%d", l[i]);
  printf("\n");
}
int main() {
  pre();
  init();
  return 0;
}
