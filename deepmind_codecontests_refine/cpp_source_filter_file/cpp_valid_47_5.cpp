#include <bits/stdc++.h>
using namespace std;
const int M = 1e4 + 5;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') f = 0;
  for (; c <= '9' && c >= '0'; c = getchar())
    x = (x << 1) + (x << 3) + (c ^ 48);
  return f ? x : -x;
}
inline int abs(int x) { return x > 0 ? x : -x; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }
inline void swap(int &a, int &b) { a ^= b ^= a ^= b; }
int n, k, a[M], c[M], t1, t2;
int main() {
  n = read(), k = read();
  for (int i = 2; i <= n; i++) {
    printf("and %d %d\n", i - 1, i);
    fflush(stdout);
    scanf("%d", &t1);
    printf("or %d %d\n", i - 1, i);
    fflush(stdout);
    scanf("%d", &t2);
    c[i] = t1 + t2;
  }
  printf("ans 1 3\n");
  fflush(stdout);
  scanf("%d", &t1);
  printf("or 1 3\n");
  fflush(stdout);
  scanf("%d", &t2);
  a[2] = c[2] - t1 - t2 + c[3] >> 1, a[1] = c[2] - a[2];
  for (register int i = 3; i <= n; i++) a[i] = c[i] - a[i - 1];
  sort(a + 1, a + 1 + n);
  printf("finish %d\n", a[k]);
  fflush(stdout);
  return 0;
}
