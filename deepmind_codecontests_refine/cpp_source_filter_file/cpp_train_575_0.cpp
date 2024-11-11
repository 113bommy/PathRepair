#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:667772160")
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
vector<int> graph[400000 + 7];
int child[400000 + 7], n, ans[400000 + 7], mx[400000 + 7][2], mid,
    node[400000 + 7][2], number_exced[400000 + 7];
bool is_dead[400000 + 7];
void dfs(int u, int par) {
  int v, mxx = 0;
  child[u] = 1;
  mx[u][0] = 0;
  mx[u][1] = 0;
  number_exced[u] = 0;
  for (int i = 0; i < graph[u].size(); i++) {
    v = graph[u][i];
    if (v == par) continue;
    dfs(v, u);
    child[u] += child[v];
    if (child[v] > mid) {
      if (child[v] - mx[v][0] <= mid)
        number_exced[u]++;
      else
        is_dead[u] = 1;
    }
    mxx = mx[v][0];
    if (child[v] <= mid) mxx = max(mxx, child[v]);
    if (mx[u][0] < mxx) {
      mx[u][1] = mx[u][0];
      node[u][1] = node[u][0];
      mx[u][0] = mxx;
      node[u][0] = v;
    } else if (mx[u][1] < mxx) {
      mx[u][1] = mxx;
      node[u][0] = v;
    }
  }
}
void dfs2(int u, int par, int pre) {
  int all, v;
  if (u != 1) {
    all = n - child[u];
    if (all > mid) {
      if (all - pre <= mid)
        number_exced[u]++;
      else
        is_dead[u] = 1;
    }
  }
  if (number_exced[u] > 1 or is_dead[u])
    ans[u] = 0;
  else
    ans[u] = 1;
  for (int i = 0; i < graph[u].size(); i++) {
    v = graph[u][i];
    if (v == par) continue;
    all = pre;
    if (node[u][0] != v)
      all = max(all, mx[u][0]);
    else if (node[u][1] != v)
      all = max(all, mx[u][1]);
    if (n - child[u] <= mid) all = max(all, n - child[u]);
    dfs2(v, u, all);
  }
}
int main() {
  int u, v;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d", &u, &v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  mid = n / 2;
  dfs(1, -1);
  dfs2(1, -1, 0);
  for (int i = 1; i <= n; i++) {
    if (i - 1) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}
