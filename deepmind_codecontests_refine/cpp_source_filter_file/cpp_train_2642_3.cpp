#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &x) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-' && c != -1)
    ;
  if (c == -1) return;
  if (c == '-') sg = 1, c = getchar();
  for (x = 0; c >= '0' && c <= '9';
       x = (x << 1) + (x << 3) + c - '0', c = getchar())
    ;
  if (sg) x = -x;
}
template <class T>
void print(T x) {
  if (x < 0) return putchar('-'), print(-x);
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  print(x / 10);
  putchar(x % 10 + '0');
}
template <class U, class V>
inline void gn(U &u, V &v) {
  gn(u);
  gn(v);
}
template <class U, class V, class W>
inline void gn(U &u, V &v, W &w) {
  gn(u);
  gn(v, w);
}
template <class T>
void println(T &x) {
  print(x);
  putchar('\n');
}
template <class T>
void printsp(T &x) {
  print(x);
  putchar(' ');
}
template <class U, class V>
inline void print(U &u, V &v) {
  printsp(u);
  println(v);
}
template <class U, class V, class W>
inline void print(U &u, V &v, W &w) {
  printsp(u);
  print(v, w);
}
int power(int a, int b, int m = 1000000007, int ans = 1) {
  for (; b; a = (long long)a * a % 1000000007, b >>= 1)
    if (b & 1) ans = (long long)ans * a % 1000000007;
  return ans;
}
vector<int> adj[300010];
int deg[300010], teem[300010];
queue<int> q;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  for (int i = 1; i <= n; i++) {
    if (adj[i].size() > 1) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (deg[u] < 2) continue;
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (teem[u] == teem[v]) {
        deg[u]--;
        deg[v]--;
      }
      if (teem[m] != teem[v]) {
        deg[u]++;
        deg[v]++;
      }
      if (deg[v] > 1) q.push(v);
    }
    teem[u] = 1 - teem[u];
  }
  for (int i = 1; i <= n; i++) printf("%d ", teem[i]);
  return 0;
}
