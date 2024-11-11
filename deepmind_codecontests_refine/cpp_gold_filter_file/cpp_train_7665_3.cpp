#include <bits/stdc++.h>
using namespace std;
struct edge {
  int from, to;
  long long cost;
};
int n, m;
vector<int> G[300001];
char s[300001];
int gindeg[300001];
vector<int> topological_sort() {
  set<int> st;
  int indeg[n];
  fill(indeg, indeg + n, 0);
  for (int i = 0; i < n; i++)
    for (int to : G[i]) indeg[to]++;
  for (int i = 0; i < n; i++) {
    gindeg[i] = indeg[i];
    if (indeg[i] == 0) st.insert(i);
  }
  vector<int> ret;
  int used[n];
  fill(used, used + n, 0);
  while (!st.empty()) {
    int node = *st.begin();
    st.erase(node);
    ret.push_back(node);
    used[node] = 1;
    for (int next : G[node]) {
      indeg[next]--;
      if (!used[next] && indeg[next] == 0) st.insert(next);
    }
  }
  return ret;
}
int main() {
  int from, to, ans = -1;
  scanf("%d %d", &n, &m);
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }
  scanf("%s", s);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &from, &to);
    G[from - 1].push_back(to - 1);
  }
  vector<int> v = topological_sort();
  if ((int)v.size() < n) {
    cout << -1 << endl;
    return 0;
  }
  int dp[26][n];
  fill(dp[0], dp[26], 0);
  for (char c = 'a'; c <= 'z'; c++) {
    int ci = (int)(c - 'a');
    for (int i = 0; i < n; i++) {
      if (gindeg[v[i]] == 0) {
        dp[ci][v[i]] = (int)(s[v[i]] == c);
      }
      for (int next : G[v[i]]) {
        dp[ci][next] = max(dp[ci][next], dp[ci][v[i]] + (int)(s[next] == c));
      }
    }
    for (int i = 0; i < n; i++) ans = max(ans, dp[ci][i]);
  }
  printf("%d\n", ans);
  return 0;
}
