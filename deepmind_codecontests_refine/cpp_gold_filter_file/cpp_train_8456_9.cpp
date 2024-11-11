#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
template <class code>
inline code read(const code &a) {
  code x = 0;
  short w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return w ? -x : x;
}
void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + 48);
}
int a[30];
bool check(int x) {
  for (int i = 1; i <= 30 && a[i] <= x + 1; i++) {
    if (a[i] == x + 1) return 1;
  }
  return 0;
}
int main() {
  a[0] = 1;
  for (int i = 1; i <= 30; i++) a[i] = a[i - 1] * 2;
  int t = read(t);
  while (t--) {
    int n = read(n), flag = 0;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        if (check(n / i)) {
          printf("%d\n", i);
          flag = 1;
          break;
        }
        if (check(i)) {
          printf("%d\n", n / i);
          flag = 1;
          break;
        }
      }
    }
    if (!flag) puts("1");
  }
  return 0;
}
