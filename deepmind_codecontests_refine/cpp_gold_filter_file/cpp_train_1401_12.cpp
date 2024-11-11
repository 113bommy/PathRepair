#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void R(T &xx) {
  xx = 0;
  char ch = getchar();
  bool F = 0;
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') F = 1, ch = getchar();
  while (ch >= '0' && ch <= '9')
    xx = xx + xx + (xx << 3) + ch - 48, ch = getchar();
  if (F) xx = -xx;
}
template <class T>
inline void add(int &x, T y) {
  for (x += y; x >= 1000000007; x -= 1000000007)
    ;
}
int n, vis[302000];
inline bool isp(int x) {
  if (x == 1) return 0;
  int lim = sqrt(x);
  for (int i = 2; i <= lim; i++)
    if (x % i == 0) return 0;
  return 1;
}
inline int g(int s) {
  for (int i = 3; i <= s; i++)
    if (isp(i) && isp(s - i)) return i;
}
int main() {
  R(n);
  int s = (n + 1) * n / 2;
  if (isp(s)) {
    for (int i = 0; i < (int)n; i++) printf("1 ");
    puts("");
    return 0;
  }
  int x;
  if (isp(s - 2))
    x = 2;
  else if (!(s & 1))
    x = g(s);
  else {
    int t = n;
    while (!isp(t)) t--;
    vis[t] = 3;
    s -= t;
    x = g(s);
  }
  for (int i = n; i >= 1; i--)
    if (!vis[i] && x >= i) vis[i] = 1, x -= i;
  for (int i = 1; i <= n; i++)
    if (!vis[i]) vis[i] = 2;
  for (int i = 1; i <= n; i++) printf("%d ", vis[i]);
  puts("");
  return 0;
}
