#include <bits/stdc++.h>
using namespace std;
int n, m, cnt;
struct node {
  int a, b, c, d;
} ans[5000100];
int main() {
  scanf("%d", &n);
  if (n % 2 == 1) {
    ans[++cnt] = (node){1, 2, 3, 0};
    ans[++cnt] = (node){1, 2, 3, 0};
    for (int i = 5; i <= n; i += 2) {
      for (int j = 2; j <= i - 2; j += 2) {
        ans[++cnt] = (node){j, i - 1, j + 1, i};
        ans[++cnt] = (node){j, i - 1, j + 1, i};
      }
      ans[++cnt] = (node){1, i - 1, i, 0};
      ans[++cnt] = (node){1, i - 1, i, 0};
    }
  } else {
    ans[++cnt] = (node){1, 2, 3, 0};
    ans[++cnt] = (node){4, 2, 3, 0};
    ans[++cnt] = (node){1, 4, 3, 0};
    ans[++cnt] = (node){1, 2, 4, 0};
    for (int i = 6; i <= n; i += 2) {
      for (int j = 3; j <= i - 2; j += 2) {
        ans[++cnt] = (node){j, i - 1, j + 1, i};
        ans[++cnt] = (node){j, i - 1, j + 1, i};
      }
      ans[++cnt] = (node){1, i - 1, i, 0};
      ans[++cnt] = (node){2, i - 1, i, 0};
      ans[++cnt] = (node){1, i - 1, 2, i};
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) {
    if (ans[i].d == 0)
      printf("3 %d %d %d\n", ans[i].a, ans[i].b, ans[i].c);
    else
      printf("4 %d %d %d %d\n", ans[i].a, ans[i].b, ans[i].c, ans[i].d);
  }
  return 0;
}
