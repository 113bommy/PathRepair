#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
template <class T>
bool get_max(T &a, const T &b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
bool get_min(T &a, const T &b) {
  return b < a ? a = b, 1 : 0;
}
int n, m;
const int maxn = 100000 + 5;
struct Adj {
  int v, c;
  Adj() {}
  Adj(int _v, int _c) : v(_v), c(_c) {}
};
vector<Adj> adj[maxn];
set<int> st[maxn];
int f[maxn];
bool update(int &u, int v) {
  if (u == -1 || u > v) {
    u = v;
    return true;
  }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    u--;
    v--;
    adj[u].push_back(Adj(v, c));
    adj[v].push_back(Adj(u, c));
  }
  for (int i = 0; i < n; i++) {
    int cnt;
    scanf("%d", &cnt);
    for (int j = 0; j < cnt; j++) {
      int x;
      scanf("%d", &x);
      st[cnt].insert(x);
    }
  }
  memset(f, -1, sizeof(f));
  queue<int> Q;
  Q.push(0);
  f[0] = 0;
  while (!Q.empty()) {
    int node = Q.front();
    int go = f[node];
    Q.pop();
    while (st[node].count(go)) go++;
    for (int i = 0; i < adj[node].size(); i++) {
      int v = adj[node][i].v;
      int c = adj[node][i].c;
      if (update(f[v], go + c)) {
        Q.push(v);
      }
    }
  }
  printf("%d\n", f[n - 1]);
  return 0;
}
