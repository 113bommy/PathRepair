#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 2e6 + 7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const double PI = acos(-1.0);
vector<int> e[N];
stack<int> st[N + N];
int data[N], prime[M], be[M], ans[N], dfn[N], times, cnt;
void init() {
  for (int i = 2; i < M; ++i)
    if (be[i] != -1) {
      prime[++cnt] = i;
      be[i] = cnt;
      for (int j = i + i; j < M; j += i) be[j] = -1;
    }
}
void dfs(int x, int fa) {
  dfn[x] = ++times;
  ans[x] = 0;
  int &res = ans[x];
  int tmp = data[x], limit = sqrt(tmp + 0.5), factor[25], total = 0;
  for (int i = 1; i <= cnt && prime[i] <= limit; ++i) {
    while (tmp % prime[i] == 0) {
      tmp /= prime[i];
      factor[++total] = i;
    }
  }
  if (tmp > 1) {
    factor[++total] = be[tmp];
  }
  for (int i = 1; i <= total; ++i) {
    int t = factor[i];
    if (!st[t].empty() && dfn[res] < dfn[st[t].top()] && st[t].top() != x) {
      res = st[t].top();
    }
    st[t].push(x);
  }
  for (int i = 0; i < e[x].size(); ++i) {
    if (e[x][i] != fa) dfs(e[x][i], x);
  }
  for (int i = 1; i <= total; ++i) {
    int t = factor[i];
    st[t].pop();
  }
}
int main(void) {
  init();
  int n, Q;
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; ++i) scanf("%d", &data[i]);
  int u, v, op;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  times = 0;
  dfs(1, 0);
  while (Q--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &u);
      printf("%d\n", ans[u] == 0 ? -1 : ans[u]);
    } else {
      scanf("%d%d", &u, &v);
      data[u] = v;
      times = 0;
      dfs(1, 0);
    }
  }
  return 0;
}
