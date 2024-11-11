#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -f;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  x *= f;
  return;
}
long long maxt(long long a, long long b) { return a > b ? a : b; }
long long mint(long long a, long long b) { return a < b ? a : b; }
void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar('0' + x);
    return;
  }
  write(x / 10);
  putchar(x % 10 + '0');
  return;
}
long long n, pri[100005], cnt, pnt;
bool vis[100005];
void pre() {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pri[++cnt] = i;
    for (int j = 1; j <= cnt && pri[j] * i <= n; j++) {
      vis[pri[j] * i] = 1;
      if (i % pri[j] == 0) break;
    }
  }
  for (int i = 1; i <= cnt; i++)
    if (pri[i] <= (n >> 1)) pnt = i;
  memset(vis, 0, sizeof(vis));
  return;
}
int main() {
  read(n);
  pre();
  write(n + pnt - cnt - 1 >> 1);
  putchar('\n');
  for (int i = pnt; i >= 1; i--) {
    long long tmp = 0;
    long long gk = 0;
    while (gk * pri[i] <= n) gk++;
    gk--;
    for (int j = gk; j; j--)
      if (!vis[pri[i] * j]) {
        vis[pri[i] * j] = 1;
        tmp++;
        if (!(tmp == 2 && j == 2)) {
          write(pri[i] * j);
          if (tmp == 2)
            putchar('\n'), tmp = 0;
          else
            putchar(' ');
        } else {
          tmp--;
          vis[pri[i] * j] = 0;
        }
      }
  }
}
