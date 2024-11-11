#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll OO = 1e18;
int di[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dj[8] = {1, -1, 0, 0, 1, 1, -1, -1};
string ys = "YES", no = "NO";
void fast() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int N = (1 << 17);
int d[N], frq[N], vis[N];
vector<int> adj[N];
int main() {
  fast();
  int n, k, mx = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    adj[x].push_back(i);
    frq[x]++;
    mx = max(mx, x);
  }
  if (adj[0].size() != 1) return cout << -1 << '\n', 0;
  if (frq[1] > k) return cout << -1 << '\n', 0;
  vector<pair<int, int> > ans;
  for (auto i : adj[1]) {
    ans.push_back({adj[0][0], i});
    vis[i]++;
  }
  for (int i = 0; i < mx; i++) {
    if (i != 0)
      if ((k - 1) * adj[i].size() < adj[i + 1].size())
        return cout << -1 << '\n', 0;
    int cur = 0;
    for (auto j : adj[i]) {
      int need = k - 1;
      if (vis[j]) {
        while (need-- && cur < adj[i + 1].size()) {
          ans.push_back({j, adj[i + 1][cur]});
          vis[adj[i + 1][cur]]++;
          cur++;
        }
      }
      if (cur == adj[i + 1].size()) break;
    }
  }
  cout << ans.size() << '\n';
  for (auto i : ans) cout << i.first << " " << i.second << '\n';
}
