#include <bits/stdc++.h>
using namespace std;
char s[100006];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k == 0 && n == 2) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  if (n == 1) {
    printf("%d\n", k);
    return 0;
  }
  if (n == 2) {
    printf("%d %d\n", 0, k);
    return 0;
  }
  int last = 0;
  if (k % 2) {
    for (int i = k + 1, j = 1; j < n; j++, i += 2) {
      printf("%d ", i);
      last = i ^ last;
    }
    printf("%d\n", last ^ k);
  } else {
    for (int i = 1; i <= n - 3; i++) {
      printf("%d ", i);
      last = i ^ last;
    }
    if (last == k)
      printf("%d %d %d\n", 1 << 17, 1 << 18, ((1 << 1) + 1) << 17);
    else
      printf("%d %d 0\n", 1 << 17, ((1 << 17) + last) ^ k);
  }
  return 0;
}
