#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adia[200010];
bool viz[200010];
int sum_in[200010];
int sum_out[200010];
bool ans[100010];
map<pair<int, int>, int> pozans;
int n;
void dfs(int nod) {
  if (nod == n) return;
  viz[nod] = 1;
  for (auto i : adia[nod]) {
    if (viz[i.first]) continue;
    sum_in[i.first] += i.second;
    sum_out[i.first] -= i.second;
    ans[pozans[{nod, i.first}]] = 1;
    if (sum_in[i.first] == sum_out[i.first] || i.first == n) {
      dfs(i.first);
    }
  }
}
int main() {
  int m, a, b, c;
  cin >> n >> m;
  for (int i(1); i <= m; i++) {
    cin >> a >> b >> c;
    pozans[{b, a}] = i;
    adia[a].push_back({b, c});
    adia[b].push_back({a, c});
    sum_out[a] += c;
    sum_out[b] += c;
  }
  dfs(1);
  for (int i(1); i <= m; i++) cout << ans[i] << '\n';
  return 0;
}
