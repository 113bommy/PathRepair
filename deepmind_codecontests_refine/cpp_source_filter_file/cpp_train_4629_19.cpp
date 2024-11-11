#include <bits/stdc++.h>
using namespace std;
int n;
void even() {
  puts("YES");
  printf("%d * %d = %d\n", 1, 2, 2);
  printf("%d * %d = %d\n", 2, 3, 6);
  printf("%d * %d = %d\n", 6, 3, 24);
  for (int i = 5; i + 1 <= n; i += 2) {
    printf("%d - %d = 1\n", i + 1, i);
    printf("1 * 24 = 24\n");
  }
}
void odd() {
  puts("YES");
  printf("5 - 1 = 4\n");
  printf("4 - 2 = 2\n");
  printf("4 * 2 = 8\n");
  printf("8 * 3 = 24\n");
  for (int i = 6; i + 1 <= n; ++i) {
    printf("%d - %d = 1\n", i + 1, i);
    printf("1 * 24 = 24\n");
  }
}
int main() {
  cin >> n;
  if (n < 4) {
    puts("NO");
    return 0;
  }
  if (n % 2 == 0)
    even();
  else
    odd();
  return 0;
}
