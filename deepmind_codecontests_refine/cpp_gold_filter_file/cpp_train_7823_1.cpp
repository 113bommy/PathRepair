#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500001;
struct Edge {
  int y, next;
} adj[MAXN * 2];
struct State {
  int size;
  long long f;
} state[MAXN];
int fch[MAXN], size[MAXN];
long long f[MAXN], ans;
int que[MAXN];
int n, m;
void add(int u, int v) {
  adj[++m] = (Edge){v, fch[u]};
  fch[u] = m;
}
long long square(int x) { return x * 1LL * x; }
long long check(State a, State b) {
  return a.f + b.f + square(n - a.size - b.size);
}
bool cross(State a, State b, State c) {
  double y0 = a.f + square(a.size);
  double x1 = b.size - a.size, y1 = b.f + square(b.size) - y0;
  double x2 = c.size - a.size, y2 = c.f + square(c.size) - y0;
  return x1 * y2 < x2 * y1;
}
bool cmp(State a, State b) { return a.size > b.size; }
void dfs(int t, int parent) {
  f[t] = 1LL << 60;
  size[t] = 1;
  for (int i = fch[t]; i != 0; i = adj[i].next) {
    int v = adj[i].y;
    if (v != parent) {
      dfs(v, t);
      size[t] += size[v];
    }
  }
  if (size[t] == 1) {
    f[t] = 1;
    return;
  }
  int m = 0;
  for (int i = fch[t]; i != 0; i = adj[i].next) {
    int v = adj[i].y;
    if (v != parent) {
      long long c = f[v] + square(size[t] - size[v]);
      if (c < f[t]) f[t] = c;
      if (parent == 0) {
        c = f[v] + square(n - size[v]);
        if (c < ans) ans = c;
      }
      state[m++] = (State){size[v], f[v]};
    }
  }
  if (m == 1) return;
  sort(state, state + m, cmp);
  int head = 0, tail = 0;
  que[0] = 0;
  for (int i = 1; i < m; i++) {
    while (head < tail && check(state[i], state[que[head]]) >=
                              check(state[i], state[que[head + 1]]))
      head++;
    long long c = check(state[i], state[que[head]]);
    if (c < ans) ans = c;
    que[++tail] = i;
    while (head + 1 < tail &&
           cross(state[que[tail - 2]], state[que[tail - 1]], state[que[tail]]))
      que[--tail] = i;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
    add(v, u);
  }
  ans = square(n);
  dfs(1, 0);
  cout << (square(n) - ans) / 2 + (n * 1LL * (n - 1) / 2) << endl;
  return 0;
}
