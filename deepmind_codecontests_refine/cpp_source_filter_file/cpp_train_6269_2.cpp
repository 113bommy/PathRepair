#include <bits/stdc++.h>
using namespace std;
const int INF = int(2e9) + 99;
set<int> prime;
void SieveOfEratosthenes(int n) {
  bool prme[n + 1];
  memset(prme, true, sizeof(prme));
  for (int p = 2; p * p <= n; p++) {
    if (prme[p] == true) {
      for (int i = p * p; i <= n; i += p) prme[i] = false;
    }
  }
  for (int p = 2; p <= n; p++)
    if (prme[p]) prime.insert(p);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> mp[n];
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    mp[a - 1].push_back(b - 1);
    mp[b - 1].push_back(a - 1);
  }
  bool rem = false;
  int ans;
  while (true) {
    rem = false;
    vector<pair<int, int>> r;
    for (int i = 0; i < n; i++) {
      if (mp[i].size() == 1) {
        rem = true;
        r.push_back(make_pair(mp[i][0], i));
        mp[i].erase(mp[i].begin());
      }
    }
    for (auto u : r) {
      for (auto it = mp[u.first].begin(); it != mp[u.first].end(); it++) {
        if (*it == u.second) {
          mp[u.first].erase(it);
          break;
        }
      }
    }
    if (rem)
      ans++;
    else {
      break;
    }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}
