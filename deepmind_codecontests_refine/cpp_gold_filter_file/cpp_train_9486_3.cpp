#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const long long oo = 1e18;
int n, m, k;
int vs[maxn], qq[maxn];
long long d[maxn];
priority_queue<pair<long long, int> > st;
vector<pair<int, int> > adj[maxn];
pair<pair<long long, int>, pair<int, int> > ed[maxn];
vector<int> ans;
void dij() {
  for (int i = (0); i < (n); i++) d[i] = oo;
  d[0] = 0;
  st.push(make_pair(0, 0));
  while (!st.empty()) {
    auto cur = st.top();
    st.pop();
    if (vs[cur.second]) continue;
    vs[cur.second] = 1;
    int u = cur.second;
    for (auto v : adj[u]) {
      if (d[v.first] > d[u] + ed[v.second].first.first) {
        d[v.first] = d[u] + ed[v.second].first.first;
        st.push(make_pair(-d[v.first], v.first));
      }
    }
  }
}
void dfs(int u) {
  qq[u] = 1;
  for (auto nxt : adj[u]) {
    int v = nxt.first;
    if (qq[v]) continue;
    if (d[v] == d[u] + ed[nxt.second].first.first && ((int)ans.size()) < k) {
      ans.push_back(nxt.second);
      dfs(v);
    }
  }
}
void saku() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = (0); i < (m); i++) {
    scanf("%d%d%lld", &ed[i].second.first, &ed[i].second.second,
          &ed[i].first.first);
    ed[i].second.first--;
    ed[i].second.second--;
    ed[i].first.second = i;
    adj[ed[i].second.first].push_back(make_pair(ed[i].second.second, i));
    adj[ed[i].second.second].push_back(make_pair(ed[i].second.first, i));
  }
  dij();
  dfs(0);
  sort(ans.begin(), ans.end());
  cout << ((int)ans.size()) << '\n';
  for (auto u : ans) {
    printf("%d ", u + 1);
  }
}
int main() {
  saku();
  return 0;
}
