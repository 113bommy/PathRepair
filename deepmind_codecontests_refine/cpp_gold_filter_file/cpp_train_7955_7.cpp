#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int A[N], B[N];
int main() {
  int n, i;
  scanf("%d", &n);
  if (n == 5) {
    puts("1 3 1");
    puts("1 2 2");
    puts("2 4 1");
    puts("4 5 1");
    puts("3 4");
    puts("3 5");
    return 0;
  }
  for (i = 1; i <= n / 2; i++) {
    printf("%d %d 1\n", i, i + n / 2);
  }
  for (; i < n; i++) {
    printf("%d %d %d\n", i, i + 1, 2 * (i - n / 2) - 1);
  }
  puts("1 3");
  for (i = 1; i < n / 2; i++) printf("%d %d\n", i, i + 1);
  return 0;
}
