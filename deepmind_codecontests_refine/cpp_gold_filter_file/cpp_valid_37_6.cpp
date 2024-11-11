#include <bits/stdc++.h>
using namespace std;
long long t;
vector<long long> adj[100001];
long long ss[100001];
void dfs(long long no, long long par = -1) {
  ss[no] = 1;
  for (auto j : adj[no]) {
    if (j != par) {
      dfs(j, no);
      ss[no] += ss[j];
    }
  }
}
const long long mod = 998244353;
long long ans[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      adj[i].clear();
    }
    for (long long i = 0; i < n - 1; i++) {
      long long aa, bb;
      cin >> aa >> bb;
      aa--;
      bb--;
      adj[aa].push_back(bb);
      adj[bb].push_back(aa);
    }
    dfs(0);
    vector<pair<long long, long long>> ss2;
    vector<long long> tt;
    for (long long i = 1; i <= n; i++) {
      ans[i] = 0;
    }
    for (long long i = 1; i < n; i++) {
      ss2.push_back({ss[i] - 1, ss[i]});
    }
    for (long long i = 1; i <= n - 1; i++) {
      if ((n - 1) % i == 0) {
        tt.push_back(i);
      }
    }
    reverse(tt.begin(), tt.end());
    for (auto j : tt) {
      ans[j] = 1;
      for (auto k : ss2) {
        long long co = 0;
        if ((k.first) % j == 0) {
          co++;
        }
        if ((k.second) % j == 0) {
          co++;
        }
        ans[j] = (ans[j] * co) % mod;
      }
      for (auto i : tt) {
        if (i > j) {
          if ((i % j) == 0) {
            ans[j] = (ans[j] - ans[i] + mod) % mod;
          }
        }
      }
    }
    for (long long i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
