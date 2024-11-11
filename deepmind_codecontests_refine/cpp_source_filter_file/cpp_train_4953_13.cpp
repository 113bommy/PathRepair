#include <bits/stdc++.h>
using namespace std;
int n, k;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    (x *= 10) += ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read(), k = read();
  if (k == 1 || k >= 4) return printf("%d\n", -1), 0;
  if (k == 2) {
    if (n <= 3) return printf("%d\n", -1), 0;
    printf("%d\n", n - 1);
    printf("%d %d\n%d %d\n", 1, 2, 2, 3);
    for (int i = 4; i <= n; i++) printf("%d %d\n", i - 1, i);
  }
  if (k == 3) {
    if (n <= 4) return printf("%d\n", -1), 0;
    printf("%d\n", n - 1);
    printf("%d %d\n%d %d\n", 1, 2, 2, 3);
    for (int i = 4; i <= n; i++) printf("%d %d\n", 3, i);
  }
  return 0;
}
