#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  T f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  x *= f;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
const int maxn = 3e5 + 5;
int n, a[maxn], tree[maxn], pos[maxn], cnt, ans;
unsigned long long ran[maxn], h[maxn], t[maxn];
int work(int pos) {
  int maxx = -1, res = 0;
  for (int i = pos + 1; a[i] != 1; ++i) {
    maxx = Max(maxx, a[i]);
    if (i >= maxx && i - maxx + 1 <= pos && (h[i] ^ h[i - maxx]) == t[maxx])
      res++;
  }
  return res;
}
int main() {
  read(n);
  srand(2005 - 12 - 30);
  a[n + 1] = 1;
  for (int i = 1; i <= n; ++i) read(a[i]);
  for (int i = 1; i <= n; ++i) ran[i] = rand();
  for (int i = 1; i <= n; ++i) t[i] = t[i - 1] ^ ran[i];
  for (int i = 1; i <= n; ++i) h[i] = h[i - 1] ^ ran[a[i]];
  for (int i = 1; i <= n; ++i)
    if (a[i] == 1) ans += work(i) + 1;
  a[n + 1] = 1;
  reverse(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) h[i] = h[i - 1] ^ ran[a[i]];
  for (int i = 1; i <= n; ++i)
    if (a[i] == 1) ans += work(i);
  print(ans);
  return 0;
}
