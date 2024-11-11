#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7f7f7f7f;
const int maxn = 2e5 + 9;
const int maxm = 2e7 + 9;
const double PI = 3.1415926;
const double eps = 1e-7;
const int mod = 1e9 + 7;
const int base = 131;
namespace IO {
long long read() {
  long long a = 1, b = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') a = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    b = (b << 3) + (b << 1) + c - '0';
    c = getchar();
  }
  return a * b;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
}  // namespace IO
using namespace IO;
int n, m;
int last[maxn], cnt = 0;
struct Edge {
  int from, to, w;
} edge[maxn];
void add(int x, int y, int z) {
  edge[++cnt].from = last[x];
  edge[cnt].to = y;
  edge[cnt].w = z;
  last[x] = cnt;
}
int d[maxn], col[maxn], v[maxn];
queue<int> q;
int main() {
  n = read(), m = read();
  if (n == 1) {
    print(0);
    putchar('\n');
    print(0);
    return 0;
  }
  int x, y, z;
  for (int i = 1; i <= m; ++i) {
    x = read(), y = read(), z = read();
    add(y, x, z);
  }
  for (int i = 1; i <= n; ++i) col[i] = -1, d[i] = inf, v[i] = 0;
  q.push(n);
  d[n] = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if (now == 1) break;
    for (int i = last[now]; i; i = edge[i].from) {
      int to = edge[i].to, w = edge[i].w;
      if (col[to] == -1) {
        col[to] = 1 - w;
      } else {
        if (col[to] == w) {
          d[to] = min(d[to], d[now] + 1);
          if (!v[to]) v[to] = 1, q.push(to);
        }
      }
    }
  }
  print(d[1] == inf ? -1 : d[1]);
  putchar('\n');
  for (int i = 1; i <= n; ++i) {
    if (col[i] == -1)
      putchar('0');
    else
      print(col[i]);
  }
  return 0;
}
