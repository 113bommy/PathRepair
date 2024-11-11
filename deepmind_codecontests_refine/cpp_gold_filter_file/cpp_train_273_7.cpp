#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5, maxm = 200000 + 5;
int n, m;
struct Edge {
  int u, v, idx, nxt;
  Edge(int u = 0, int v = 0) : u(u), v(v) {}
  bool operator==(const Edge& rhs) const { return u == rhs.u && v == rhs.v; }
} edge[maxm];
int head[maxn], top;
int stamp, dfn[maxn], low[maxn], belong[maxn], bccno, bccsz[maxn];
bool iscut[maxn], vis[maxm];
stack<Edge> st;
vector<int> bcc[maxn];
void init() {
  memset(head, -1, sizeof(head));
  memset(dfn, 0, sizeof(dfn));
  memset(low, 0, sizeof(low));
  memset(iscut, 0, sizeof(iscut));
  memset(belong, 0, sizeof(belong));
  memset(bccsz, 0, sizeof(bccsz));
  memset(vis, 0, sizeof(vis));
  top = 0;
  stamp = 0;
  bccno = 0;
  while (!st.empty()) st.pop();
}
void addedge(int u, int v, int idx) {
  edge[top].u = u;
  edge[top].v = v;
  edge[top].idx = idx;
  edge[top].nxt = head[u];
  head[u] = top++;
  edge[top].u = v;
  edge[top].v = u;
  edge[top].idx = idx;
  edge[top].nxt = head[v];
  head[v] = top++;
}
void tarjan(int u, int fa) {
  dfn[u] = low[u] = ++stamp;
  int child = 0;
  for (int i = head[u]; i != -1; i = edge[i].nxt) {
    int v = edge[i].v, cidx = edge[i].idx;
    if (v == fa) continue;
    if (!dfn[v]) {
      st.push(edge[i]);
      child++;
      tarjan(v, u);
      if (low[v] < low[u]) low[u] = low[v];
      if (low[v] >= dfn[u]) {
        iscut[u] = 1;
        bcc[++bccno].clear();
        do {
          int uu = st.top().u, vv = st.top().v, idx = st.top().idx;
          if (belong[uu] != bccno) belong[uu] = bccno, bccsz[bccno]++;
          if (belong[vv] != bccno) belong[vv] = bccno, bccsz[bccno]++;
          bcc[bccno].push_back(idx);
          if (idx == cidx) {
            st.pop();
            break;
          }
          st.pop();
        } while (!st.empty());
      }
    } else if (dfn[v] < dfn[u]) {
      st.push(edge[i]);
      if (dfn[v] < low[u]) low[u] = dfn[v];
    }
  }
  if (u == fa && child <= 1) iscut[u] = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    addedge(u, v, i);
  }
  for (int i = 1; i <= n; i++)
    if (!dfn[i]) tarjan(i, i);
  vector<int> ans;
  for (int i = 1; i <= bccno; i++) {
    if (bcc[i].size() == bccsz[i]) {
      ans.insert(ans.end(), bcc[i].begin(), bcc[i].end());
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
