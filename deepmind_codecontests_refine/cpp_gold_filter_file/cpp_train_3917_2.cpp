#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int f[202002];
int loop[202020];
int size[202002];
int c[200202];
int find(int x) {
  if (x == f[x])
    return x;
  else
    return f[x] = find(f[x]);
}
int main() {
  int n = read();
  for (int i = 1; i <= 2 * n; i++) {
    f[i] = i;
    size[i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    if (x == y) loop[x] = 1;
    int fx = find(x), fy = find(y);
    if (fx != fy) {
      f[fx] = fy;
      loop[fy] |= loop[fx];
      size[fy] += size[fx];
      size[fx] = 0;
    } else
      c[fx] = 1;
  }
  long long ans = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (find(i) == i && loop[i] == 0) {
      if (c[i] != 0) {
        ans = ans * 2;
      } else
        ans = ans * size[i];
    }
    ans %= 1000000007;
  }
  cout << ans;
  return 0;
}
