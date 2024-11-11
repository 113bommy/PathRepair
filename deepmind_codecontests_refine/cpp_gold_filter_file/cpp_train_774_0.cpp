#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  if (a.second == b.second) return a.first < b.first;
  return (a.second < b.second);
}
vector<long long int> vis(500005), ans(500005), temp;
vector<long long int> alist[500005];
void dfs(long long int n) {
  vis[n] = 1;
  temp.push_back(n);
  for (auto i : alist[n]) {
    if (vis[i] == 0) dfs(i);
  }
}
void solve() {
  long long int b, g;
  cin >> b;
  long long int bz[b];
  for (long long int i = 0; i < b; i++) cin >> bz[i];
  cin >> g;
  long long int gz[g];
  for (long long int i = 0; i < g; i++) cin >> gz[i];
  sort(bz, bz + b);
  sort(gz, gz + g);
  long long int ans = 0;
  for (long long int i = 0; i < b; i++) {
    for (long long int j = 0; j < g; j++) {
      if (abs(bz[i] - gz[j]) <= 1) {
        ans++;
        gz[j] = 10000;
        break;
      }
    }
  }
  cout << ans;
}
signed main() {
  long long int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
