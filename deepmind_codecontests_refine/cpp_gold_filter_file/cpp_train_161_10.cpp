#include <bits/stdc++.h>
using namespace std;
int s[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0, 0};
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  if (n == 0) {
    printf("1");
    return 0;
  }
  while (n) {
    ans += s[n % 16];
    n /= 16;
  }
  printf("%d\n", ans);
  return 0;
}
