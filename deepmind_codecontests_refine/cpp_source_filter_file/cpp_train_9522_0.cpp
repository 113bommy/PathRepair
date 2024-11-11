#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 7;
vector<int> adjlist[maxn];
int freq[maxn], n, m, u, v;
void dfs(int cur, int len) {
  if (len == 0) {
    freq[cur]++;
    return;
  }
  for (auto u : adjlist[cur]) dfs(u, len - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adjlist[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    dfs(i, 2);
    freq[i] = 0;
    for (int j = 1; j <= n; j++) {
      ans = ans + (freq[j] * freq[j] - 1) / 2;
      freq[j] = 0;
    }
  }
  cout << ans;
  return 0;
}
