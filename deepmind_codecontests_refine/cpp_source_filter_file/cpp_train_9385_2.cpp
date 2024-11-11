#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500100;
struct seg {
  seg *fe, *fd;
  int meio, mex, l, r;
  seg(int x, int y) {
    meio = (x + y) / 2;
    l = x, r = y;
    mex = 0;
    if (x == y) return;
    fe = new seg(x, meio);
    fd = new seg(meio + 1, y);
  }
  void up(int pos, int novo) {
    if (l == r) {
      mex = novo;
      return;
    }
    if (pos <= meio)
      fe->up(pos, novo);
    else
      fd->up(pos, novo);
    mex = max(fe->mex, fd->mex);
  }
  int get(int a, int b) {
    if (l >= a && r <= b) return mex;
    if (l > b || r < a) return 0;
    return max(fe->get(a, b), fd->get(a, b));
  }
};
seg st(1, MAXN);
vector<int> grafo[MAXN];
int nex[MAXN], sub[MAXN];
int r[MAXN];
void dfs(int x) {
  sub[x]++;
  for (int i = 0; i < grafo[x].size(); i++) {
    int at = grafo[x][i];
    dfs(at);
    sub[x] += sub[at];
  }
}
void solve(int x, int v) {
  r[x] = v;
  v--;
  for (int i = 0; i < grafo[x].size(); i++) {
    int at = grafo[x][i];
    solve(at, v);
    v -= sub[at];
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n + 1; i++) r[i] = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &nex[i]);
      if (nex[i] == -1)
        grafo[i + 1].push_back(i), nex[i] = i + 1;
      else
        grafo[nex[i]].push_back(i);
    }
    dfs(n + 1);
    solve(n + 1, n + 1);
    bool f = true;
    for (int i = 1; i <= n; i++) st.up(i, r[i]);
    for (int i = 1; i <= n; i++) {
      if (r[i] <= 0) f = false;
      if (i + 1 <= nex[i] - 1 && st.get(i + 1, nex[i] - 1) > r[i]) f = false;
    }
    for (int i = 1; i <= n + 1; i++) {
      grafo[i].clear();
      sub[i] = 0;
    }
    if (f == false) {
      printf("-1\n");
      continue;
    }
    for (int i = 1; i <= n; i++) printf("%d ", r[i]);
    printf("/n");
  }
}
