#include <bits/stdc++.h>
using namespace std;
int n, head[100005];
long long f[100005][2];
struct data {
  int next, to;
} edge[100005];
inline void add(int x, int y) {
  static int cnt = 0;
  edge[++cnt].to = y;
  edge[cnt].next = head[x];
  head[x] = cnt;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  cin >> n;
  for (int x, i = 2; i <= n; ++i) x = read(), add(x, i);
  for (int x = n; x; --x) {
    f[x][0] = 0;
    f[x][1] = 1;
    if (!head[x]) continue;
    for (int i = head[x]; i; i = edge[i].next) {
      int y = edge[i].to, t0 = f[x][0], t1 = f[x][1];
      f[x][0] += t0 * f[y][0] % 1000000007 + t1 * f[y][1] % 1000000007;
      f[x][1] += t0 * f[y][1] % 1000000007 + t1 * f[y][0] % 1000000007;
      f[x][0] %= 1000000007;
      f[x][1] %= 1000000007;
    }
    f[x][0] *= 2;
    f[x][1] *= 2;
    f[x][0] %= 1000000007;
    f[x][1] %= 1000000007;
    long long cnt = 1, cnt0 = 1, cnt1 = 0;
    for (int i = head[x]; i; i = edge[i].next) {
      int y = edge[i].to, t0 = cnt0, t1 = cnt1;
      cnt += cnt * f[y][0] % 1000000007;
      cnt0 += t1 * f[y][1] % 1000000007;
      cnt1 += t0 * f[y][1] % 1000000007;
      cnt %= 1000000007;
      cnt0 %= 1000000007;
      cnt1 %= 1000000007;
    }
    f[x][0] -= cnt1;
    f[x][1] -= cnt;
    f[x][0] = f[x][0] % 1000000007 + 1000000007 % 1000000007;
    f[x][1] = f[x][1] % 1000000007 + 1000000007 % 1000000007;
  }
  cout << (f[1][0] + f[1][1]) % 1000000007 << endl;
  return 0;
}
