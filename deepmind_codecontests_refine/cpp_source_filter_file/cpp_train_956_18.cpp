#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -f;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  x *= f;
}
void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) return;
  print(x / 10), putchar(x % 10 + 48);
}
void write(int x) {
  if (!x)
    putchar('0');
  else
    print(x);
  putchar('\n');
}
const int maxn = 1e6 + 10;
const int inf = 1e9;
const double eps = 1e-8;
const int mod = 1e9 + 7;
int n, m, d, c[maxn];
void put(int x, int a) {
  while (x--) printf("%d ", a);
}
int main() {
  read(n), read(m), read(d);
  int s = 0;
  for (int i = 1; i <= m; i++) read(c[i]), s += c[i];
  int p = (n - s) / (m + 1) + ((n - s) % (m + 1) != 0);
  if (p > d) return puts("NO"), 0;
  puts("YES");
  int t = (n - s) % (m + 1);
  if (!t) t = m + 1;
  t--;
  put(p, 0);
  for (int i = 1; i <= m; i++) {
    put(c[i], i);
    if (t)
      put(p, 0), t--;
    else
      put(p - 1, 0);
  }
  puts("");
  return 0;
}
