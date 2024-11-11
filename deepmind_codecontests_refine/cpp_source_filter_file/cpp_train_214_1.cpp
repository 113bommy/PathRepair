#include <bits/stdc++.h>
using namespace std;
vector<int> e[400000];
bool used[400000];
void dfs(int now) {
  if (used[now]) {
    used[now] = false;
    for (int i = 0; i < e[now].size(); i++) {
      dfs(e[now][i]);
    }
  }
}
int main() {
  memset(used, true, sizeof used);
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    b += n;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  int ans = 0;
  for (int i = 0; i < n + m; i++) {
    ans += used[i];
    dfs(i);
  }
  cout << ans;
  return 0;
}
