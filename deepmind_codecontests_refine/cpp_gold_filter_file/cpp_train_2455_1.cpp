#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  int ch = getchar(), f = 1;
  while (!isdigit(ch) && (ch != '-') && (ch != EOF)) ch = getchar();
  if (ch == '-') {
    f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void rt(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10)
    rt(x / 10), putchar(x % 10 + '0');
  else
    putchar(x + '0');
}
const int maxn = 10;
int n, a[maxn];
int main() {
  n = rd();
  for (int i = int(1); i <= (int)(n); i++) a[i] = rd();
  sort(a + 1, a + n + 1);
  rt(a[(n + 1) / 2]), putchar('\n');
}
