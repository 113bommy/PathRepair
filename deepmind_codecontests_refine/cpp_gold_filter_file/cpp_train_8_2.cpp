#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n;
int a[maxn], b[maxn];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  x = x * 10 + ch - '0';
  return x * f;
}
inline void writ(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) writ(x / 10);
  putchar(x % 10 + '0');
}
inline void write(int x) {
  writ(x);
  putchar('\n');
}
inline void writt(int x) {
  writ(x);
  putchar(' ');
}
int main() {
  int ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) a[i] = read(), ++b[a[i]];
  for (int i = 1; i <= b[8]; ++i) {
    int t = min(i, (n - i) / 10);
    ans = max(ans, t);
  }
  write(ans);
  return 0;
}
