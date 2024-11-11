#include <bits/stdc++.h>
using namespace std;
int n, m, r, x, comp;
set<int> st;
set<pair<int, int> > second;
bool edge(int a, int b) {
  if (a > b) swap(a, b);
  if (second.find({a, b}) == second.end()) return 1;
  return 0;
}
void dfs(int v) {
  set<int>::iterator it;
  vector<int> q;
  for (it = st.begin(); it != st.end(); ++it)
    if (edge(*it, v)) q.push_back(*it);
  for (int k = 0; k < q.size(); ++k) st.erase(q[k]);
  for (int k = 0; k < q.size(); ++k) dfs(q[k]);
  return;
}
int main() {
  cin >> n >> m >> r;
  for (int k = 2; k <= n; ++k) st.insert(k);
  for (int k = 1; k <= m; ++k) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    x += (a == 1);
    second.insert({a, b});
  }
  for (int k = 2; k <= n; ++k)
    if (edge(1, k) && st.find(k) != st.end()) dfs(1), ++comp;
  if (n - x <= r || comp > r || st.size())
    cout << "impossible";
  else
    cout << "possible";
  return 0;
}
