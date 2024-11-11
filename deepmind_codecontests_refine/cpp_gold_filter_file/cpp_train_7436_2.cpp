#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  char s[105] = {};
  scanf("%d %d", &n, &k);
  cin >> s;
  if (k == 1) {
    for (int i = 0; i < n - 1; ++i) {
      printf("PRINT %c\n", s[i]);
      printf("RIGHT\n");
    }
    printf("PRINT %c\n", s[n - 1]);
  } else if (k == n) {
    for (int i = n - 1; i > 0; --i) {
      printf("PRINT %c\n", s[i]);
      printf("LEFT\n");
    }
    printf("PRINT %c\n", s[0]);
  } else {
    if (n - k <= k - 1) {
      for (int i = 1; i <= n - k; i++) printf("RIGHT\n");
      for (int i = n - 1; i > 0; --i) {
        printf("PRINT %c\n", s[i]);
        printf("LEFT\n");
      }
      printf("PRINT %c\n", s[0]);
    } else {
      for (int i = 1; i <= k - 1; i++) printf("LEFT\n");
      for (int i = 0; i < n - 1; ++i) {
        printf("PRINT %c\n", s[i]);
        printf("RIGHT\n");
      }
      printf("PRINT %c\n", s[n - 1]);
    }
  }
  return 0;
}
