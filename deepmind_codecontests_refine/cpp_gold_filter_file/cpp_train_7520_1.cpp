#include <bits/stdc++.h>
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
struct elem {
  int i, v, p;
  long long cost;
};
int main(void) {
  int N;
  scanf("%d", &N);
  vector<long long> a(N);
  vector<int> b(N), c(N);
  for (int i = 0; i < (int)(N); i++) scanf("%lld%d%d", &a[i], &b[i], &c[i]);
  vector<vector<int> > adj(N);
  for (int i = 0; i < (int)(N - 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long ans = 0;
  vector<int> X(N), Y(N);
  stack<elem> st;
  st.push({0, 0, -1, a[0]});
  while (!st.empty()) {
    elem &e = st.top();
    X[e.v] = (b[e.v] && !c[e.v]), Y[e.v] = (!b[e.v] && c[e.v]);
    if (e.i < adj[e.v].size()) {
      int to = adj[e.v][e.i++];
      if (e.p == to) continue;
      st.push({0, to, e.v, min(e.cost, a[to])});
    } else {
      st.pop();
      for (auto u : adj[e.v]) {
        if (u == e.p) continue;
        X[e.v] += X[u], Y[e.v] += Y[u];
      }
      int t = min(X[e.v], Y[e.v]);
      ans += (long long)t * 2 * e.cost;
      X[e.v] -= t, Y[e.v] -= t;
    }
  }
  if (X[0] + Y[0] > 0) ans = -1;
  printf("%lld\n", ans);
  return 0;
}
