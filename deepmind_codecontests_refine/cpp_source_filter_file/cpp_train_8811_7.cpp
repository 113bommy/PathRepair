#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int f[2][200010], q[200010];
int main() {
  int now = 0, lst = 1;
  int n = read(), k = read();
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  while (k--) {
    int l = read(), r = read();
    swap(now, lst);
    int t = 1, w = 0;
    memcpy(f[now], f[lst], sizeof(f[now]));
    for (int i = 1; i <= min(n, r); i++) {
      while (t <= w && q[t] < i - r + l) ++t;
      while (t <= w && f[lst][q[w]] > f[lst][i]) --w;
      q[++w] = i, f[now][i] = min(f[now][i], f[lst][q[t]] + 2);
    }
    t = 1, w = 0;
    for (int i = r; i >= 0; i--) {
      while (t <= w && q[t] < l - i) ++t;
      while (t <= w && f[lst][q[w]] >= f[lst][r - i]) --w;
      q[++w] = r - i, f[now][i] = min(f[now][i], f[lst][q[t]] + 1);
    }
  }
  if (f[now][n] >= 0x3f3f3f3f)
    printf("Hungry\n");
  else
    printf("Full\n%d\n", f[now][n]);
  return 0;
}
