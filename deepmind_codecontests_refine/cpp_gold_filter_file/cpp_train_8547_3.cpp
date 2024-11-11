#include <bits/stdc++.h>
using namespace std;
int n, m, rt, K, nu, a[300012], mx[300012], fa[300012], In[300012], Out[300012],
    de[300012], ti = 0, vi[300012], cad[300012];
vector<int> e[300012], e1[300012];
queue<int> q;
vector<int> ca, st;
void dfs(int x) {
  st.push_back(x);
  vi[x] = ti;
  ++nu;
  for (auto y : e[x])
    if (vi[y] != ti) dfs(y);
}
void solve() {
  int i, x, y;
  K = 0;
  for (x = 0; x <= n + 1; x++) de[x] = e1[x].size(), fa[x] = -1;
  for (i = 0; i <= n + 1; i++) {
    mx[i] = 1;
    if (!de[i]) q.push(i);
  }
  while (!q.empty()) {
    x = q.front();
    q.pop();
    for (auto p : e[x]) {
      if (!(--de[p])) q.push(p);
      if (mx[x] + 1 > mx[p]) mx[p] = mx[x] + 1, fa[p] = x;
    }
  }
  for (i = 0; i <= n + 1; i++)
    if (mx[i] > K) K = mx[i], rt = i;
  a[K = 1] = rt;
  while (~fa[rt]) rt = fa[rt], a[++K] = rt;
  reverse(a + 1, a + K + 1);
  for (i = 2; i < K; i++) {
    x = a[i - 1];
    y = a[i + 1];
    ++ti;
    ca.clear();
    for (auto p : e[x]) vi[p] = ti;
    for (auto p : e1[y])
      if (vi[p] == ti) ca.push_back(p);
    cad[i] = 0;
    if (ca.size() == 2) cad[i] = ca[0] ^ ca[1] ^ a[i];
  }
  ++ti;
  nu = 0;
  for (i = K; i >= 1; i--) {
    dfs(a[i]);
    In[a[i]] = nu;
    if (x = cad[i - 1]) {
      st.clear();
      dfs(x);
      In[x] = nu;
      for (auto p : st) vi[p] = 0, --nu;
    }
  }
}
int ans = 0;
int main() {
  scanf("%d%d", &n, &m);
  int i, x, y;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e1[y].push_back(x);
  }
  for (i = 1; i <= n; i++)
    e[0].push_back(i), e[i].push_back(n + 1), e1[n + 1].push_back(i),
        e1[i].push_back(0);
  solve();
  for (i = 0; i <= n + 1; i++) swap(e[i], e1[i]), swap(In[i], Out[i]);
  solve();
  for (i = 1; i <= n; i++)
    if (In[i] + Out[i] - 2 >= n) ++ans;
  printf("%d", ans);
  return 0;
}
