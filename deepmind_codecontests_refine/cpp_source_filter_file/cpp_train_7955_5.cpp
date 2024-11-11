#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
  return x * f;
}
int n;
int main() {
  n = read();
  if (n == 5) {
    puts("5 1 1");
    puts("1 3 3");
    puts("3 4 5");
    puts("2 4 2");
    puts("1 2");
    puts("4 5");
    return 0;
  }
  for (int i = 1; i <= n / 2; i++) printf("%d %d %d\n", i, i + n / 2, 1);
  for (int i = n / 2 + 1; i < n; i++)
    printf("%d %d %d\n", i, i + 1, 2 * (i - n / 2) - 1);
  for (int i = 1; i <= n / 2 - 1; i++) printf("%d %d\n", i, i + 1);
  puts("1 3");
  return 0;
}
