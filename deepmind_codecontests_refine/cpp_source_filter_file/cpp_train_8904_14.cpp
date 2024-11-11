#include <bits/stdc++.h>
using namespace std;
const int N = 660;
int i, j, k, n, m, q, ch;
int a[N][N];
void R(int &x) {
  x = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
}
int sqr(int x) { return x * x; }
int Js1() {
  int ans = 0, i;
  for (i = 1; i <= m; i++) ans += sqr(a[n / 2][i] - a[n / 2 + 1][i]);
  return ans;
}
int Js2() {
  int ans = 0, i;
  for (i = 1; i <= m; i++) ans += sqr(a[1][i] - a[n][i]);
  return ans;
}
int main() {
  R(q);
  while (q--) {
    R(n);
    R(m);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) R(a[i][j]);
    if (n & 1) {
      puts("YES");
      continue;
    }
    if (Js1() <= Js2())
      puts("YES");
    else
      puts("NO");
  }
}
