#include <stdio.h>
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(void) {
  int n, ans = 0, i;
  rep(i, 3) {
    scanf("%d", &n);
    ans += n;
  }
  printf("%d\n", ans);
  return 0;
}
