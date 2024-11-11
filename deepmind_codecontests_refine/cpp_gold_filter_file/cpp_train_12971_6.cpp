#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int d[N], a[N], n;
vector<int> G[N];
int mx;
int cnt[1 << 24];
void dfs(int u) {
  mx = max(mx, d[u]);
  for (int v : G[u]) {
    d[v] = d[u] + 1;
    dfs(v);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    G[p].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) d[i] = mx + 1 - d[i];
  vector<int> vec;
  int grundy = 0;
  for (int i = 1; i <= n; ++i)
    if (d[i] & 1)
      vec.push_back(i), grundy ^= a[i];
    else
      cnt[a[i]]++;
  long long ans = 0;
  if (grundy == 0) {
    ans += 1LL * (int)vec.size() * ((int)vec.size() - 1) / 2;
    ans += 1LL * (n - (int)vec.size()) * (n - (int)vec.size() - 1) / 2;
  }
  for (int v : vec) {
    int k = (a[v] ^ grundy);
    ans += cnt[k];
  }
  cout << ans << endl;
}
