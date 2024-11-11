#include <bits/stdc++.h>
using namespace std;
const int N = int(5e5) + 5;
const int inf = (int)1e9 + 7;
int n;
int main() {
  scanf("%d", &n);
  if (n <= 3) {
    printf("NO");
  } else {
    printf("YES\n");
    if (n % 2 == 0) {
      printf("1 * 2 = 2\n");
      printf("2 * 3 = 6\n");
      printf("6 * 4 = 24\n");
      for (int i = 5; i <= n; i += 2) {
        printf("%d - %d = 1\n", i + 1, i);
        printf("24 * 1 = 24\n");
      }
    } else {
      printf("5 - 1 = 4\n");
      printf("4 - 2 = 2\n");
      printf("4 * 2 = 8\n");
      printf("8 * 3 = 24\n");
      for (int i = 6; i <= n; i += 2) {
        printf("%d - %d", i + 1, i);
        printf("24 * 1 = 24\n");
      }
    }
  }
  return 0;
}
