#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
string s[N];
int lp[N], dp[50][50];
vector<int> adj[N];
string t;
int ans;
inline int PF(char c, int k) {
  int &ret = dp[c - 'a'][k];
  if (~ret) return ret;
  while (k && c != t[k]) k = lp[k - 1];
  if (c == t[k]) k++;
  return ret = k;
}
inline void ff() {
  for (int i = 1, k = 0; i < t.size(); i++) {
    k = PF(t[i], k);
    lp[i] = k;
  }
}
inline void solve(int u, int k) {
  for (auto c : s[u]) {
    k = PF(c, k);
    if (k == (int)t.size()) {
      ans++;
      k = lp[k - 1];
    }
  }
  for (auto v : adj[u]) solve(v, k);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof dp);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p >> s[i];
    adj[p].push_back(i);
  }
  cin >> t;
  ff();
  solve(1, 0);
  cout << ans << endl;
  return 0;
}
