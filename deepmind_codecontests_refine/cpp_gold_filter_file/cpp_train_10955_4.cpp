#include <bits/stdc++.h>
using namespace std;
const long long int N = 300009;
const long long int mod = 1000000007;
long long int t, n, x, y;
vector<long long int> a[N];
vector<long long int> dp;
void dfs(long long int z, long long int pr) {
  for (auto &it : a[z]) {
    if (it == pr) continue;
    dp[it] = dp[z] + 1;
    dfs(it, z);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(cin.failbit);
  ;
  cin >> n;
  dp.assign(n, 0);
  for (long long int i = 0; i < (n - 1); ++i) {
    cin >> x >> y;
    x--, y--;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  long long int ans = (n - 1);
  long long int l = 0;
  long long int rt = -1;
  for (long long int i = 0; i < (n); ++i) {
    if ((long long int)((a[i]).size()) == 1) {
      l++;
      rt = i;
    }
  }
  for (long long int i = 0; i < (n); ++i) {
    for (auto &it : a[i]) {
      if ((long long int)((a[it]).size()) == 1) {
        l--;
        break;
      }
    }
  }
  dfs(rt, -1);
  for (long long int i = 0; i < (n); ++i) {
    if ((long long int)((a[i]).size()) == 1 and ((dp[i] % 2) == 1)) {
      cout << 3 << " ";
      break;
    }
    if (i == (n - 1)) {
      cout << 1 << " ";
    }
  }
  cout << (ans - l) << "\n";
  return 0;
}
