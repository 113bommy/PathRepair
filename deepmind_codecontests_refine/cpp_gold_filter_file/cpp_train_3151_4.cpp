#include <bits/stdc++.h>
using namespace std;
const int N = 200001;
vector<int> adj[N];
long long val[N];
vector<int> ans, a1;
void dfs(int u, int par) {
  for (auto i : adj[u]) {
    if (i != par) {
      dfs(i, u);
      if (val[i] > 0) {
        val[u] += val[i];
        ans.push_back(i);
      } else {
        a1.push_back(i);
      }
    }
  }
}
void solve() {
  int n;
  cin >> n;
  int b[n];
  for (int i = 0; i < n; i++) {
    cin >> val[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] != -1) {
      b[i]--;
      adj[i].push_back(b[i]);
      adj[b[i]].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == -1) {
      dfs(i, -1);
      ans.push_back(i);
    }
  }
  long long score = 0;
  int n1 = ans.size(), n2 = a1.size();
  for (int i = 0; i < n1; i++) {
    score += val[ans[i]];
  }
  for (int i = n2 - 1; i >= 0; i--) {
    score += val[a1[i]];
  }
  cout << score << "\n";
  for (int i = 0; i < n1; i++) {
    cout << ans[i] + 1 << " ";
  }
  for (int i = n2 - 1; i >= 0; i--) {
    cout << a1[i] + 1 << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
