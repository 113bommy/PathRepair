#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > G[100001];
set<int> st;
bool dfs(int n, int pr, bool flag) {
  bool ans = false;
  for (int i = 0; i < G[n].size(); i++) {
    pair<int, int> p;
    p = G[n][i];
    if (p.first == pr) continue;
    bool temp = dfs(p.first, n, p.second == 2);
    ans = ans || temp;
  }
  if (flag) {
    if (ans == true)
      return true;
    else {
      st.insert(n);
      return true;
    }
  } else
    return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b, ti;
    cin >> a >> b >> ti;
    G[a].push_back({b, ti});
    G[b].push_back({a, ti});
  }
  dfs(1, -1, false);
  cout << st.size() << "\n";
  for (auto it = st.begin(); it != st.end(); it++) {
    cout << (*it) << " ";
  }
}
