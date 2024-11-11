#include <bits/stdc++.h>
using namespace std;
const long long int mxN = 510;
long long int n, m, a[mxN][mxN], dp[mxN][1100];
bool ans = 0;
vector<long long int> vans;
void print(vector<long long int> v) {
  for (auto x : v) cout << x << " ";
  cout << endl;
}
bool positive_xor(long long int i, long long int xr, vector<long long int> v) {
  if (ans == 1) return 1;
  if (i == n) {
    if (xr > 0) {
      for (auto x : v) vans.push_back(x);
      ans = 1;
      return 1;
    } else {
      return 0;
    }
  }
  for (long long int j = 0; j < m; j++) {
    long long int cxr = xr ^ a[i][j];
    if (dp[i + 1][cxr] == -1) {
      v.push_back(j + 1);
      dp[i + 1][cxr] = positive_xor(i + 1, xr ^ a[i][j], v);
      v.pop_back();
    }
    if (dp[i + 1][cxr] == 1) return 1;
  }
  return 0;
}
void solve() {
  cin >> n >> m;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < m; j++) cin >> a[i][j];
  memset(dp, -1, sizeof(dp));
  vector<long long int> v;
  if (!positive_xor(0, 0, v)) {
    cout << "NIE\n";
  } else {
    cout << "TAK\n";
    print(vans);
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
