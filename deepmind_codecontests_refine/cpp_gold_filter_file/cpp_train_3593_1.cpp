#include <bits/stdc++.h>
template <typename T>
bool Chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool Chkmin(T &x, T y) {
  return y < x ? x = y, true : false;
}
const int MAXN = 26 + 10, MAXM = 3e6 + 100, oo = 0x3f3f3f3f;
int base;
int n;
int m;
int a[MAXN];
int f[MAXM];
int vis[MAXM];
int ch[MAXM];
int Gcd(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int Rnd(int x) {
  while (x > m) x -= m;
  while (x <= 0) x += m;
  return x;
}
void Search(int x, int fr, int type) {
  vis[x] = true;
  f[x] = fr;
  for (int i = 1; i <= m; i += m / base) {
    int next = Rnd((i * 2 + type) - x);
    if (vis[next] == 0)
      Search(next, fr, type);
    else
      break;
  }
}
void Exec(int type, int fr, int size) {
  for (int i = 1, _ = m; i <= _; i++)
    if (vis[i] == 0) Search(i, i, type);
  int p = fr;
  for (int i = 1, _ = n; i <= _; i++) {
    int cnt = a[i] / size;
    while (cnt--) {
      while (f[p] != p) p++;
      ch[p] = i;
      p++;
    }
  }
  printf("%d\n", base);
  for (int i = 1, _ = m; i <= _; i++) putchar('a' + ch[f[i]] - 1);
  puts("");
}
void Solve() { Exec(1, 1, base); }
void Special1() {
  printf("%d\n", m);
  for (int i = 1, _ = m; i <= _; i++) putchar('a');
  puts("");
}
void Special2() {
  int s;
  for (int i = 1, _ = n; i <= _; i++)
    if (a[i] & 1) s = i;
  for (int i = 1; i <= m; i += m / base) {
    vis[i] = true;
    ch[i] = s;
    f[i] = 1;
  }
  a[s] -= base;
  Exec(0, 2, base * 2);
}
void Special3() {
  printf("%d\n", 0);
  for (int i = 1, _ = n; i <= _; i++)
    for (int j = 1, _ = a[i]; j <= _; j++) putchar('a' + i - 1);
  puts("");
}
int main() {
  if (fopen("C.in", "r") != NULL) {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
  }
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1, _ = n; i <= _; i++) {
    scanf("%d", &a[i]);
    m += a[i];
    if (a[i] & 1) cnt++;
    base = Gcd(base, a[i]);
  }
  if (n == 1)
    Special1();
  else if (cnt == 1)
    Special2();
  else if (cnt >= 2)
    Special3();
  else
    Solve();
  return 0;
}
