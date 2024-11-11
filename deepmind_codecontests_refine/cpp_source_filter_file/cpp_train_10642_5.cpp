#include <bits/stdc++.h>
using namespace std;
int n, m, k, qq, h[200005], par[200005][18], at[200005], s[200005], u[200005],
    cnt, ord[200005];
vector<int> v[200005], vv[200005];
pair<int, int> p[200005];
struct cmp {
  bool operator()(const pair<pair<int, int>, int>& a,
                  const pair<pair<int, int>, int>& b) {
    int ta = a.first.first / s[a.first.second];
    int tb = b.first.first / s[b.first.second];
    if (ta != tb) return ta > tb;
    if (a.first.second != b.first.second)
      return a.first.second > b.first.second;
    return a.second > b.second;
  }
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    int ta = a.first / s[a.second];
    int tb = b.first / s[b.second];
    if (ta != tb) return ta > tb;
    return a.second > b.second;
  }
};
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>,
               cmp>
    q;
void dfs(int a, int b) {
  par[a][0] = b;
  for (int i = 1; i < 18; i++) par[a][i] = par[par[a][i - 1]][i - 1];
  for (int i : v[a])
    if (i != b) {
      h[i] = h[a] + 1;
      dfs(i, a);
    }
  ord[a] = cnt++;
}
int lca(int a, int b) {
  if (h[a] > h[b]) swap(a, b);
  for (int i = 0; i < 18; i++)
    if ((h[b] - h[a]) & (1 << i)) b = par[b][i];
  if (a == b) return a;
  for (int i = 17; i >= 0; i--)
    if (par[a][i] != par[b][i]) {
      a = par[a][i];
      b = par[b][i];
    }
  return par[a][0];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int ta, tb;
    scanf("%d%d", &ta, &tb);
    v[ta].push_back(tb);
    v[tb].push_back(ta);
  }
  dfs(1, 0);
  scanf("%d", &qq);
  while (qq--) {
    vector<int> ss;
    scanf("%d%d", &k, &m);
    for (int i = 0; i < k; i++) {
      scanf("%d%d", at + i, s + i);
      ss.push_back(at[i]);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d", u + i);
      ss.push_back(u[i]);
    }
    sort(ss.begin(), ss.end(), [&](int a, int b) { return ord[a] < ord[b]; });
    if (ss.back() != 1) ss.push_back(1);
    vector<int> st{1}, lc;
    for (int i : ss) {
      int tmp = lca(i, st.back());
      while (h[tmp] < h[st.back()] && h[tmp] <= h[st[st.size() - 2]]) {
        int wtf = st.back();
        st.pop_back();
        vv[wtf].push_back(st.back());
        vv[st.back()].push_back(wtf);
      }
      if (h[tmp] > st.back())
        st.push_back(tmp);
      else if (h[tmp] < st.back()) {
        int wtf = st.back();
        st.pop_back();
        vv[wtf].push_back(tmp);
        vv[tmp].push_back(wtf);
        st.push_back(tmp);
      }
      if (i != st.back()) st.push_back(i);
      p[i].first = INT_MAX;
      p[tmp].first = INT_MAX;
      lc.push_back(tmp);
    }
    for (int i = 0; i < k; i++) q.emplace(p[at[i]] = {s[i] - 1, i}, at[i]);
    while (!q.empty()) {
      auto ta = q.top().first;
      int tb = q.top().second;
      q.pop();
      if (p[tb] != ta) continue;
      for (int i : vv[tb]) {
        auto tc = make_pair(ta.first + abs(h[tb] - h[i]), ta.second);
        if (cmp{}(p[i], tc)) q.emplace(p[i] = tc, i);
      }
    }
    for (int i = 0; i < m; i++)
      printf("%d%c", p[u[i]].second + 1, " \n"[i == m - 1]);
    for (int i : ss) vector<int>().swap(vv[i]);
    for (int i : lc) vector<int>().swap(vv[i]);
  }
}
