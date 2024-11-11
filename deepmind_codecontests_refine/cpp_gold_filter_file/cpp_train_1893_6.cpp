#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double PI = acos(-1);
const long long MOD = 1000000007;
const long long FMOD = 998244353;
const long double eps = 1e-9;
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
long long a[5005], dp[5005][5005];
const long long inf = 1e6 + 2;
signed main() {
  long long n;
  cin >> n;
  long long dist[n][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      dist[i][j] = inf;
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        dist[i][j] = 1;
      }
    }
    dist[i][i] = 0;
  }
  for (long long k = 0; k < n; k++) {
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  long long k;
  cin >> k;
  long long a[k];
  for (long long i = 0; i < k; i++) {
    cin >> a[i];
    a[i]--;
  }
  vector<long long> ans;
  ans.push_back(0);
  for (long long i = 2; i < k; i++) {
    if (dist[a[ans.back()]][a[i]] < i - ans.back()) {
      ans.push_back(i - 1);
    }
  }
  ans.push_back(k - 1);
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << a[x] + 1 << " ";
  }
}
