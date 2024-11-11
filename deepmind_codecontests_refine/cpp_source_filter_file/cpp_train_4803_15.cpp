#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
struct edge {
  int u, v, len;
  edge(int U, int V, int Len) : u(U), v(V), len(Len) {}
};
vector<pair<int, int> > ve[maxn];
vector<edge> g;
int n, m, in[maxn], num[maxn];
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g.push_back(edge(a, b, c));
    ve[a].push_back(make_pair(b, c));
  }
}
bool checke(int x) {
  int tot = 0;
  memset(in, 0, sizeof(in));
  for (int i = 0; i < g.size(); i++) {
    if (g[i].len > x) in[g[i].v]++;
  }
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    if (in[i] == 0) st.push(i);
  }
  while (!st.empty()) {
    int now = st.top();
    st.pop();
    for (int i = 0; i < ve[now].size(); i++) {
      if (ve[now][i].second > x && (--in[ve[now][i].first]) == 0) {
        st.push(ve[now][i].first);
      }
    }
    num[now] = tot++;
  }
  return tot != n;
}
void binary_search() {
  int l = 0, r = 1e9 + 10;
  while (r - l > 1) {
    int mid = l + r >> 1;
    if (checke(mid)) {
      l = mid;
    } else
      r = mid;
  }
  checke(r);
  vector<int> ans;
  for (int i = 0; i < m; i++) {
    int u = g[i].u;
    int v = g[i].v;
    if (num[u] > num[v]) ans.push_back(i + 1);
  }
  printf("%d %d\n", r, ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
}
int main() {
  init();
  binary_search();
  return 0;
}
