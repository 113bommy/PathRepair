#include <bits/stdc++.h>
using namespace std;
namespace IO {
void read(int &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while ('0' > c || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  x *= f;
}
void read(long long &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while ('0' > c || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  x *= f;
}
void write(int x) {
  if (x < 10)
    putchar(x + '0');
  else {
    write(x / 10);
    putchar(x % 10 + '0');
  }
}
void write(long long x) {
  if (x < 10)
    putchar(x + '0');
  else {
    write(x / 10);
    putchar(x % 10 + '0');
  }
}
}  // namespace IO
using namespace IO;
int n, m;
int dis_u, dis_v, dis;
int dep[1500005], dp[1500005][25];
void init() {
  n = 4;
  dep[1] = 1;
  dep[2] = dep[3] = dep[4] = 2;
  dp[2][0] = dp[3][0] = dp[4][0] = 1;
  dis = 2;
  dis_u = 2;
  dis_v = 3;
}
void update(int u) {
  for (int i = 1; i <= 20; i++) dp[u][i] = dp[dp[u][i - 1]][i - 1];
}
int lca(int u, int v) {
  int s = 0;
  if (u == v) return 0;
  if (dep[u] > dep[v]) swap(u, v);
  for (int i = 20; i >= 0; i--)
    if (dep[u] <= dep[dp[v][i]]) {
      s = s + (1 << i);
      v = dp[v][i];
    }
  if (u == v) return s;
  for (int i = 20; i >= 0; i--)
    if (dp[u][i] != dp[v][i]) {
      s = s + (1 << (i + 1));
      u = dp[u][i];
      v = dp[v][i];
    }
  return s + 2;
}
int main() {
  init();
  read(m);
  for (int i = 1, u; i <= m; i++) {
    read(u);
    dp[n + 1][0] = u;
    dp[n + 2][0] = u;
    dep[n + 1] = dep[u] + 1;
    dep[n + 2] = dep[u] + 1;
    update(n + 1);
    update(n + 2);
    int t1 = lca(n + 1, dis_u);
    int t2 = lca(n + 1, dis_v);
    if (max(t1, t2) > dis) {
      if (t1 > t2) {
        dis_v = n + 1;
        dis = t1;
      } else {
        dis_u = n + 1;
        dis = t2;
      }
    }
    cout << dis << '\n';
    n += 2;
  }
  return 0;
}
