#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
const long long MOD = 1e9 + 7;
long long co[N];
long long dp[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long a[n + 1];
  long long c = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] <= m)
      co[a[i]]++;
    else
      c++;
  }
  if (c == n) {
    return cout << 1 << "0\n", 0;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j += i) {
      dp[j] += co[i];
    }
  }
  long long ma = 0, id = -1;
  for (int i = m; i >= 1; i--) {
    if (dp[i] >= ma) {
      ma = dp[i];
      id = i;
    }
  }
  cout << id << " ";
  vector<long long> ans;
  for (int i = 1; i <= n; i++) {
    if (id % a[i] == 0) {
      ans.push_back(i);
    }
  }
  cout << (long long)ans.size() << endl;
  for (auto x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
