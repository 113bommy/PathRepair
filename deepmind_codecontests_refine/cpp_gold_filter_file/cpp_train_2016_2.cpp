#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
inline void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int P;
int n, a[30], p[30];
int st[30];
inline void dfs(int dpt, int s, int Xor, int r) {
  if (dpt > n && s && !Xor && !r) {
    puts("Yes");
    int i, cnt = 0;
    for (i = 1; i <= n; ++i) cnt += st[i];
    write(cnt), putchar('\n');
    for (i = 1; i <= n; ++i)
      if (st[i]) write(p[i]), putchar(' ');
    putchar('\n');
    exit(0);
  }
  if (dpt > n) return;
  st[dpt] = 0, dfs(dpt + 1, s, Xor, r);
  st[dpt] = 1,
  dfs(dpt + 1, 1, Xor ^ a[dpt], (r * (a[dpt] >= 10 ? 100 : 10) + a[dpt]) % P);
}
int main() {
  int m, i, x;
  cin >> m >> P;
  for (i = 1; i <= m; ++i) {
    cin >> x;
    if (x < 25) a[++n] = x, p[n] = i;
  }
  dfs(1, 0, 0, 0);
  puts("No");
  return 0;
}
