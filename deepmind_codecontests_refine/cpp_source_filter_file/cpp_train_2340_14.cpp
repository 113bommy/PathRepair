#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int cnt = 1;
int n, minl[100010], minr[100010], maxl[100010], maxr[100010], ans[100010],
    cc = 0;
void solve(int cur) {
  if (cur > n) return;
  if (cnt > minl[cur]) {
    printf("IMPOSSIBLE\n");
    exit(0);
  }
  while (cnt < maxl[cur]) solve(++cnt);
  ans[++cc] = cur;
  if (cnt > minr[cur]) {
    printf("IMPOSSIBLE\n");
    exit(0);
  }
  while (cnt < maxr[cur]) solve(++cnt);
}
int main() {
  n = inp();
  int c = inp();
  for (int i = 1; i <= n; i++) minl[i] = minr[i] = 2147483647;
  while (c--) {
    int a = inp();
    int b = inp();
    if (a >= b) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
    char type[10];
    scanf("%s", type + 1);
    if (type[1] == 'R') {
      minr[a] = std::min(minr[a], b);
      maxr[a] = std::max(maxr[a], b);
    } else {
      minl[a] = std::min(minl[a], b);
      maxl[a] = std::max(maxl[a], b);
    }
  }
  solve(1);
  while (cnt < n) solve(++cnt);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  putchar('\n');
}
