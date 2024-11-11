#include <bits/stdc++.h>
using namespace std;
const int mxn = 100006;
const int mxm = 100006;
const int MOD = 1000000007;
int N, M;
bool v[mxn];
int c[mxn];
template <class Edge, int mxn, int mxm>
struct Graph {
  int n;
  int m;
  int fe[mxn + 1];
  int ne[mxm + 2];
  int ev[mxm + 2];
  Edge e[mxm + 2];
  void clear(int n) {
    this->n = n;
    fill(fe, fe + n + 1, 0);
    m = 1;
  }
  void add1(int a, int b, Edge edge) {
    ++m;
    ne[m] = fe[a];
    fe[a] = m;
    ev[m] = b;
    e[m] = edge;
  }
  void add2(int a, int b, Edge edge) {
    add1(a, b, edge);
    add1(b, a, edge);
  }
  bool dfs(int x, int col) {
    if (v[x]) return c[x] == col;
    v[x] = true;
    c[x] = col;
    for (int i = fe[x]; i; i = ne[i])
      if (!dfs(ev[i], c[x] ^ e[i])) return false;
    return true;
  }
};
Graph<int, mxn, mxm * 2> G;
void EXEC() {
  scanf("%d%d", &N, &M);
  G.clear(N);
  for (int i = 1; i <= M; ++i) {
    int L, R, W;
    scanf("%d%d%d", &L, &R, &W);
    W = !W;
    G.add2(L, R, W);
  }
  int cnt = 0;
  for (int i = 1; i <= N; ++i)
    if (!v[i]) {
      ++cnt;
      if (!G.dfs(i, 0)) {
        cout << 0 << endl;
        return;
      }
    }
  int ans = 1;
  for (int i = 2; i <= cnt; ++i) ans = ans * 2 % MOD;
  cout << ans << endl;
}
int main() {
  EXEC();
  return 0;
}
