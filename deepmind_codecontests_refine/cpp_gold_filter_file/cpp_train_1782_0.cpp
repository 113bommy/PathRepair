#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ull = unsigned long long;
const int mxx = 100001;
vector<int> adj[mxx], v;
int n, temp, vis[mxx], child[mxx], rnk[mxx];
int dfs(int u) {
  vis[u] = 1;
  int subs = 1;
  for (auto v : adj[u]) {
    if (!vis[v]) {
      subs += dfs(v);
    }
  }
  if (subs > 1)
    rnk[u] = subs - 1;
  else
    rnk[u] = 1;
  return rnk[u];
}
int main() {
  ios_base ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (ll(i) = ll(2); (i) < (ll)(n + 1); ++(i)) {
    cin >> temp;
    adj[temp].push_back(i);
    adj[i].push_back(temp);
  }
  dfs(1);
  for (int i = 0; i < mxx; i++)
    if (rnk[i] != 0) v.push_back(rnk[i]);
  int rem = n - v.size();
  if (rem > 0)
    while (rem--) v.push_back(1);
  sort((v).begin(), (v).end());
  for (auto i : v) cout << i << " ";
}
