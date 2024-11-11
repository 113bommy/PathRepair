#include <bits/stdc++.h>
using namespace std;
int s[10002];
void solve(int a, int b, int c) {
  int x, x1, x2, x3;
  printf("and %d %d\n", a, b);
  fflush(stdout);
  scanf("%d", &x1);
  printf("or %d %d\n", a, b);
  fflush(stdout);
  scanf("%d", &x);
  x1 += x;
  printf("and %d %d\n", b, c);
  fflush(stdout);
  scanf("%d", &x2);
  printf("or %d %d\n", b, c);
  fflush(stdout);
  scanf("%d", &x);
  x2 += x;
  printf("and %d %d\n", a, c);
  fflush(stdout);
  scanf("%d", &x3);
  printf("or %d %d\n", a, c);
  fflush(stdout);
  scanf("%d", &x);
  x3 += x;
  x = 1ll * x1 + x2 + x3 >> 1;
  s[a] = x - x2;
  s[b] = x - x3;
  s[c] = x - x1;
}
void solve2(int a, int b) {
  int x1, x;
  printf("and %d %d\n", a, b);
  fflush(stdout);
  scanf("%d", &x1);
  printf("or %d %d\n", a, b);
  fflush(stdout);
  scanf("%d", &x);
  x1 += x;
  s[b] = x1 - s[a];
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  solve(1, 2, 3);
  for (int i = 4; i <= n; ++i) solve2(i - 1, i);
  sort(s + 1, s + n + 1);
  printf("finish %d", s[k]);
}
