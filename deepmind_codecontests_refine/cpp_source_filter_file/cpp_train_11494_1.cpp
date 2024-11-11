#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
bool vis[N];
vector<int> ans;
void dfs(int pos) {
  if (vis[pos]) return;
  vis[pos] = 1;
  dfs(pos * 2 % n);
  dfs((pos * 2 + 1) % n);
  ans.push_back(pos);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }
  dfs(0);
  reverse(ans.begin(), ans.end());
  ans.push_back(0);
  for (auto &i : ans) cout << i << ' ';
  return 0;
}
