#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while ((c < '0' || c > '9') && c - '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
const int N = 1e5 + 10;
int dis[N], first[N], ne[N << 3], to[N << 3], val[N << 3], cnt = 0;
inline void add(int x, int y, int c) {
  cnt++;
  ne[cnt] = first[x];
  first[x] = cnt;
  to[cnt] = y;
  val[cnt] = c;
}
struct pig {
  int x;
  int y;
  int id;
} q[N];
inline int min(int x, int y) { return x < y ? x : y; }
inline int jue(int x) { return x < 0 ? (-x) : x; }
int n, m, sx, sy, tx, ty;
int s, t;
bool cmp1(pig f1, pig f2) { return f1.x < f2.x; }
bool cmp2(pig f1, pig f2) { return f1.y < f2.y; }
inline int suan() {
  memset(dis, 127, sizeof(dis));
  priority_queue<pair<int, int> > que;
  que.push(make_pair(0, 0));
  dis[s] = 0;
  while (!que.empty()) {
    int u = que.top().second;
    que.pop();
    for (int i = first[u]; i; i = ne[i]) {
      int v = to[i];
      if (dis[v] > dis[u] + val[i]) {
        dis[v] = dis[u] + val[i];
        que.push(make_pair(-dis[v], v));
      }
    }
  }
  return dis[t];
}
int main() {
  n = read();
  m = read();
  t = m + 1;
  sx = read();
  sy = read();
  tx = read();
  ty = read();
  for (int i = 1; i <= m; i++) q[i].x = read(), q[i].y = read(), q[i].id = i;
  for (int i = 1; i <= m; i++) {
    int jl = min(jue(q[i].x - sx), jue(q[i].y - sy));
    add(s, i, jl);
    jl = jue(q[i].x - tx) + jue(q[i].y - ty);
    add(i, t, jl);
  }
  sort(q + 1, q + m + 1, cmp1);
  for (int i = 1; i < m; i++) {
    int jl = min(jue(q[i].x - q[i + 1].x), jue(q[i].y - q[i + 1].y));
    add(q[i].id, q[i + 1].id, jl);
    add(q[i + 1].id, q[i].id, jl);
  }
  sort(q + 1, q + m + 1, cmp2);
  add(s, t, jue(tx - sx) + jue(ty - sy));
  for (int i = 1; i < m; i++) {
    int jl = min(jue(q[i].x - q[i + 1].x), jue(q[i].y - q[i + 1].y));
    add(q[i].id, q[i + 1].id, jl);
    add(q[i + 1].id, q[i].id, jl);
  }
  cout << suan() << "\n";
  return 0;
}
