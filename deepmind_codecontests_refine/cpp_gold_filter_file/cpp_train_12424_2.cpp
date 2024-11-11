#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int N = 100000 + 10;
vector<int> e[N];
const int V = N * 5;
struct State {
  int v, q;
  State() {}
  State(int a, int b) : v(a), q(b) {}
} q[V];
int head, tail;
int isV[N];
int k, S, T;
bool bfs(int m) {
  head = tail = 0;
  int dis[N];
  memset((dis), 0, sizeof(dis));
  q[tail++] = State(S, m);
  while (head < tail) {
    State t = q[head++];
    if (head == V) head = 0;
    if (t.v == T) return true;
    if (t.q == 0) continue;
    for (int i = 0; i < e[t.v].size(); ++i)
      if (t.q > dis[e[t.v][i]]) {
        dis[e[t.v][i]] = t.q;
        if (isV[e[t.v][i]])
          q[tail++] = State(e[t.v][i], m);
        else
          q[tail++] = State(e[t.v][i], t.q - 1);
        if (tail == V) tail = 0;
      }
  }
  return false;
}
int main() {
  int n, m;
  scanf("%d", &(n)), scanf("%d", &(m)), scanf("%d", &(k));
  memset((isV), 0, sizeof(isV));
  for (int i(0), _n(k); i < _n; ++i) {
    int x;
    scanf("%d", &(x));
    isV[x] = 1;
  }
  while (m--) {
    int a, b;
    scanf("%d", &(a)), scanf("%d", &(b));
    e[a].push_back(b);
    e[b].push_back(a);
  }
  scanf("%d", &(S)), scanf("%d", &(T));
  int ans = -1, l = 0, r = N;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (bfs(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", (ans));
  return 0;
}
