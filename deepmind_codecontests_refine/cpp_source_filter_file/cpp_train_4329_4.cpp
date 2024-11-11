#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100;
const int MAXM = 1e6 + 100;
const long long MOD = 1e9 + 7;
vector<pair<int, int>> pr[MAXM];
map<vector<pair<int, int>>, long long> for_ans;
long long fact[MAXM];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int sz;
    cin >> sz;
    map<int, int> for_pr;
    for (int j = 0; j < sz; ++j) {
      int curr;
      cin >> curr;
      for_pr[curr]++;
    }
    for (auto e : for_pr) {
      pr[e.first].push_back({i, e.second});
    }
  }
  for (int i = 0; i <= m; ++i) {
    sort(pr[i].begin(), pr[i].end());
    for_ans[pr[i]]++;
  }
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i < MAXM; ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  long long ans = 1;
  for (auto &e : for_ans) {
    ans *= fact[e.second];
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
