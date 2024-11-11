#include <bits/stdc++.h>
using namespace std;
int ma[200008];
int fa[200008];
int main() {
  int n, s;
  scanf("%d%d", &n, &s);
  if (n == s) {
    printf("NO\n");
  } else {
    if (n * 2 > s) {
      printf("NO\n");
      return 0;
    }
    printf("YES\n");
    s -= n * 2;
    printf("%d ", 2 + s);
    for (int i = 2; i <= n; i++) {
      printf("2 ");
    }
    printf("\n");
    printf("1\n");
  }
}
