#include <bits/stdc++.h>
using namespace std;
long long n, m, c;
vector<long long> vec[300005];
vector<long long> G[300005];
long long ans[300005];
set<long long> S;
vector<long long> tmp;
void dfs(int v, int p) {
  for (auto u : vec[v]) {
    if (ans[u]) S.erase(ans[u]), tmp.push_back(ans[u]);
  }
  for (auto u : vec[v]) {
    if (ans[u]) continue;
    ans[u] = *S.begin();
    S.erase(S.begin()), tmp.push_back(ans[u]);
  }
  for (auto z : tmp) S.insert(z);
  tmp.clear();
  for (auto u : G[v])
    if (u != p) dfs(u, v);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long(i) = (1); (i) <= (n); (i)++) {
    long long s, x;
    cin >> s;
    (c) = max((c), (s));
    for (long long(j) = (1); (j) <= (s); (j)++) {
      cin >> x;
      vec[i].push_back(x);
    }
  }
  long long u, v;
  for (long long(i) = (1); (i) <= (n - 1); (i)++) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (long long(i) = (1); (i) <= (c); (i)++) S.insert(i);
  dfs(1, 0);
  for (long long(i) = (1); (i) <= (m); (i)++)
    if (ans[i] == 0) ans[i] = 1;
  cout << c << endl;
  for (long long(i) = (1); (i) <= (m); (i)++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
