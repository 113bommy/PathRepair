#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
inline int reint() {
  int d;
  scanf("%d", &d);
  return d;
}
inline long relong() {
  long l;
  scanf("%ld", &l);
  return l;
}
inline char rechar() {
  scanf(" ");
  return getchar();
}
inline double redouble() {
  double d;
  scanf("%lf", &d);
  return d;
}
inline string restring() {
  string s;
  cin >> s;
  return s;
}
const int maxn = 1000;
int n;
struct Edge {
  int u, v, d;
  Edge(int u, int v, int d) : u(u), v(v), d(d) {}
  bool operator<(const Edge& rhs) const { return d < rhs.d; }
};
priority_queue<Edge> q;
int vis[maxn];
int p[maxn];
int a;
int main(void) {
  cin >> n;
  for (int i = (2); i <= (2 * n); i++) {
    for (int j = (1); j <= (i - 1); j++) {
      cin >> a;
      q.push(Edge(i, j, a));
    }
  }
  while (!q.empty()) {
    Edge e = q.top();
    q.pop();
    if (!vis[e.u] && !vis[e.v]) {
      vis[e.u] = 1;
      vis[e.v] = 1;
      p[e.u] = e.v;
      p[e.v] = e.u;
    }
  }
  for (int i = (1); i <= (2 * n); i++) {
    printf("%d%c", p[i], i == 2 * n ? '\n' : ' ');
  }
  return 0;
}
