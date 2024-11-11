#include <bits/stdc++.h>
using namespace std;
int S = 256 * 256, cnt[256 * 256];
vector<int> adj[256 * 256], ans;
void dfs(int u) {
  if (!adj[u].empty()) {
    int v = adj[u].back();
    adj[u].pop_back();
    dfs(v);
  }
  ans.push_back(u);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string st;
    cin >> st;
    int u = st[0] * 256 + st[1];
    int v = st[1] * 256 + st[2];
    adj[u].push_back(v);
    cnt[v]++;
  }
  int b1 = 0, b2 = 0, b3 = 0, start = 0;
  for (int i = 0; i < S; i++) {
    if (!adj[i].empty()) start = i;
  }
  for (int i = 0; i < S; i++) {
    if (adj[i].size() == cnt[i] + 1)
      b1++, start = i;
    else if (adj[i].size() + 1 == cnt[i])
      b2++;
    else if (adj[i].size() != cnt[i])
      b3++;
  }
  if (b3 || b2 > 1 || b2 > 1) {
    cout << "NO\n";
    return 0;
  }
  dfs(start);
  reverse(ans.begin(), ans.end());
  if (ans.size() != n + 1) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n" << char(ans[0] / 256);
  for (int i = 0; i < ans.size(); i++) {
    cout << char(ans[i] % 256);
  }
  cout << endl;
  return 0;
}
