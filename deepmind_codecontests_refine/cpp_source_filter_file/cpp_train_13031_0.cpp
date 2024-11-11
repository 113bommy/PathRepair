#include <bits/stdc++.h>
using namespace std;
int N = 1e6, SZ = 320, INF = 1 << 29;
long long LINF = (1LL << 60), mod = 1e9 + 7;
const long double eps = 1e-8, PI = acos(-1.0);
inline int dcmp(double x, double y = 0.0) { return abs(x - y) < eps; }
template <typename Type>
inline Type ru(Type &v) {
  static char READ_DATA;
  static int SIGNAL_INPUT = 1;
  while ((READ_DATA = getchar()) < '0' || READ_DATA > '9')
    if (READ_DATA == '-')
      SIGNAL_INPUT = -1;
    else if (READ_DATA == EOF)
      return EOF;
  v = READ_DATA - '0';
  while ((READ_DATA = getchar()) >= '0' && READ_DATA <= '9')
    v = v * 10 + READ_DATA - '0';
  v *= SIGNAL_INPUT;
  return v;
}
template <typename A, typename B>
inline int ru(A &x, B &y) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  return 2;
}
template <typename A, typename B, typename C>
inline int ru(A &x, B &y, C &z) {
  if (ru(x) == EOF) return EOF;
  ru(y);
  ru(z);
  return 3;
}
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
struct Edge {
  int u, v, w, nxt;
  Edge(int _u = 0, int _v = 0, int _w = 0, int _nxt = -1) {
    u = _u;
    v = _v;
    w = _w;
    nxt = _nxt;
  }
};
const int maxn = 2e5 + 20;
vector<int> g[maxn];
int n, k, vis[maxn];
queue<int> q;
int main() {
  ru(n, k);
  for (int i = 1; i <= k; i++) {
    int u, v;
    ru(u, v);
    g[i].push_back(u + n);
    g[i].push_back(v + n);
    g[u + n].push_back(i);
    g[v + n].push_back(i);
  }
  for (int i = 1; i <= k; i++)
    if (!vis[i]) {
      q.push(i);
      vis[i] = 1;
      int u;
      while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int &v : g[u]) {
          if (u <= k) {
            if (!vis[v]) {
              q.push(v);
              vis[u] = 1;
              vis[v] = 1;
            }
          } else {
            if (!vis[v]) {
              q.push(v);
              vis[v] = -1;
            }
          }
        }
      }
    }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    if (vis[i] == -1) {
      ++ans;
    }
  }
  printf("%d", ans);
}
