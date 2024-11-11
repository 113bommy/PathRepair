#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int INF2 = 0x3f3f3f3f;
const long long INF64 = 1e18;
const double INFD = 1e30;
const double EPS = 1e-6;
const double PI = 3.1415926;
const long long MOD = 1e9 + 7;
inline int read() {
  int X = 0, w = 0;
  char ch = 0;
  while (!isdigit(ch)) {
    w |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) X = (X << 3) + (X << 1) + (ch ^ 48), ch = getchar();
  return w ? -X : X;
}
int n, m, k;
int CASE;
const int MAXN = 100005;
int T;
struct Edge {
  int fr;
  int to;
  long long dis;
  Edge() = default;
  Edge(int fr, int to, long long dis) : fr(fr), to(to), dis(dis) {}
  bool operator<(const Edge& b) const { return this->dis < b.dis; }
};
long long fanin[MAXN];
long long fanout[MAXN];
long long val[MAXN];
vector<Edge> G[MAXN];
vector<Edge> ans;
bool vis[MAXN];
stack<int> st;
void dfs(int u) {
  vis[u] = true;
  for (auto v : G[u]) {
    if (!vis[v.to]) {
      if (val[v.to] < 0) {
        st.push(v.to);
        dfs(v.to);
      } else if (val[v.to] > 0) {
        while (val[v.to] > 0 && !st.empty()) {
          if (val[v.to] + val[st.top()] >= 0) {
            ans.push_back({st.top(), v.to, -val[st.top()]});
            val[v.to] += val[st.top()];
            val[st.top()] = 0;
            st.pop();
          } else {
            ans.push_back({st.top(), v.to, val[v.to]});
            val[st.top()] += val[v.to];
            val[v.to] = 0;
          }
        }
        if (!st.empty()) dfs(v.to);
      }
    }
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].push_back({u, v, w});
    fanin[v] += w;
    fanout[u] += w;
  }
  for (int i = 1; i <= n; i++) {
    val[i] += fanin[i];
    val[i] -= fanout[i];
  }
  vector<int> pos;
  vector<int> neg;
  for (int i = 1; i <= n; i++) {
    if (val[i] < 0) {
      pos.push_back(i);
    } else if (val[i] > 0) {
      neg.push_back(i);
    }
  }
  int j = 0;
  int ps = pos.size(), ns = neg.size();
  for (int i = 0; i < ps && j < ns; i++) {
    while (i < ps && j < ns && val[pos[i]]) {
      if (val[pos[i]] + val[neg[j]] >= 0) {
        bool flag = (val[pos[i]] + val[neg[j]] == 0);
        ans.push_back({pos[i], neg[j], -val[pos[i]]});
        val[neg[j]] -= val[pos[i]];
        i++;
        if (flag) j++;
      } else {
        ans.push_back({pos[i], neg[j], val[neg[j]]});
        val[pos[i]] -= val[neg[j]];
        j++;
      }
    }
  }
  printf("%d\n", ans.size());
  for (auto a : ans) {
    printf("%d %d %lld\n", a.fr, a.to, a.dis);
  }
}
int main() {
  solve();
  return 0;
}
