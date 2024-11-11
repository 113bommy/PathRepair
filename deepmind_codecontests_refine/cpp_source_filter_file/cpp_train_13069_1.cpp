#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x = 0, f = 0;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 5e5 + 10;
long long Head[N], Next[N], To[N], Val[N], cnt;
inline void Add(long long x, long long y, long long z) {
  Next[++cnt] = Head[x];
  Head[x] = cnt;
  To[cnt] = y;
  Val[cnt] = z;
}
long long n, a[N], dis[N], vis[N];
inline void Dijkstra(long long s) {
  priority_queue<pair<long long, long long> > q;
  memset((dis), (0x3f), sizeof((dis)));
  q.push(make_pair(0, s));
  dis[s] = 0;
  while (!q.empty()) {
    register long long x = q.top().second;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (register long long i = Head[x]; i; i = Next[i]) {
      register long long y = To[i];
      if (dis[y] > dis[x] + Val[i])
        dis[y] = dis[x] + Val[i], q.push(make_pair(-dis[y], y));
    }
  }
}
signed main() {
  n = read();
  for (register long long i = 1; i <= n; ++i) a[i] = read(), Add(i, a[i], 1);
  for (register long long i = 1; i < n; ++i) Add(i, i + 1, 1), Add(i + 1, i, 1);
  Dijkstra(1);
  for (register long long i = 1; i <= n; ++i) cout << dis[i] << " ";
  return 0;
}
