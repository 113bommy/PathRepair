#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adjlist[1000050];
bool done[1000050], use[100050];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adjlist[a].push_back(b);
  }
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    if (!done[i]) {
      v.push_back(i);
      for (auto j : adjlist[i]) done[j] = true;
    }
  }
  memset(done, false, sizeof done);
  reverse(v.begin(), v.end());
  for (auto i : v) {
    if (!done[i]) {
      use[i] = true;
      done[i] = true;
      for (auto j : adjlist[i]) done[j] = true;
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++)
    if (use[i]) ans.push_back(i);
  cout << ans.size() << "\n";
  for (auto i : ans) cout << i << " ";
}
