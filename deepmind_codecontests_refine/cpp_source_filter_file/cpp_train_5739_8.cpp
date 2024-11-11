#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char zf = 1;
  char ch = getchar();
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') zf = -1, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * zf;
}
void write(long long y) {
  if (y < 0) putchar('-'), y = -y;
  if (y > 9) write(y / 10);
  putchar(y % 10 + 48);
}
void writeln(const long long y) {
  write(y);
  putchar('\n');
}
int i, j, k, m, n, x, y, z, cnt;
int q[1100010], h, t, dis[1100010];
bool vis[1100010];
struct xg {
  int x, y, z;
} pre[1100010], cz[100010];
int a[100010];
void query() {
  vis[0] = 1;
  q[t = 1] = 0;
  while (h < t) {
    x = q[++h];
    for (register int i = 1; i <= n; i++)
      for (register int j = 1; j < i; j++) {
        int v1 = i - j, v2 = i, v3 = i + j;
        if (v1 >= 1 && v3 <= n) {
          int val = x ^ (1 << v1) ^ (1 << v2) ^ (1 << v3);
          if (!vis[val]) {
            vis[val] = 1;
            pre[val] = {v1, v2, v3};
            dis[val] = dis[x] + 1;
            q[++t] = val;
          }
        }
      }
  }
  int sum = 0;
  for (register int i = 1; i <= n; i++) sum += a[i] * (1 << i);
  if (!vis[sum]) {
    puts("NO");
    exit(0);
  }
  puts("Yes");
  writeln(dis[sum] + cnt);
  for (register int i = 1; i <= cnt; i++)
    printf("%d %d %d\n", cz[i].x, cz[i].y, cz[i].z);
  while (sum) {
    printf("%d %d %d\n", pre[sum].x, pre[sum].y, pre[sum].z);
    sum = sum ^ (1 << pre[sum].x) ^ (1 << pre[sum].y) ^ (1 << pre[sum].z);
  }
}
void did(int x, int y, int z) {
  cz[++cnt] = {x, y, z};
  a[x] ^= 1;
  a[y] ^= 1;
  a[z] ^= 1;
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) a[i] = read();
  if (n < 20) query();
  while (n >= 20) {
    while (n >= 20 && a[n] == 0) n--;
    if (n < 20) query();
    if (a[n] && a[n - 1] && a[n - 2]) {
      did(n, n - 1, n - 2);
    } else if (a[n] && !a[n - 1] && !a[n - 2]) {
      did(n, n - 3, n - 6);
    } else if (a[n] && !a[n - 1] && a[n - 2]) {
      did(n, n - 1, n - 2);
    } else {
      if (!a[n - 3] && !a[n - 4] && !a[n - 5]) {
        did(n - 1, n - 4, n - 7);
        did(n, n - 4, n - 8);
      } else if (!a[n - 3] && a[n - 4] && a[n - 5]) {
        did(n, n - 4, n - 8);
        did(n - 1, n - 5, n - 9);
      } else if (a[n - 3] && !a[n - 4] && a[n - 5]) {
        did(n, n - 3, n - 6);
        did(n - 1, n - 5, n - 9);
      } else if (a[n - 3] && a[n - 4] && !a[n - 5]) {
        did(n, n - 3, n - 6);
        did(n - 1, n - 4, n - 7);
      } else if (a[n - 3] && a[n - 4] && a[n - 5]) {
        did(n - 1, n - 3, n - 5);
        did(n, n - 4, n - 8);
      } else if (a[n - 3]) {
        did(n, n - 3, n - 6);
        did(n - 1, n - 6, n - 11);
      } else if (a[n - 4]) {
        did(n, n - 4, n - 8);
        did(n - 1, n - 6, n - 11);
      } else if (a[n - 5]) {
        did(n, n - 5, n - 9);
        did(n - 1, n - 4, n - 7);
      }
    }
  }
  return 0;
}
