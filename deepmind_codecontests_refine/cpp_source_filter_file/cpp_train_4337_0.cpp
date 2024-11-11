#include <bits/stdc++.h>
using namespace std;
long long a[110], n, k, gl;
long long dp[110][50100];
bool b[110][50100];
long long rec(int t, long long x) {
  if (x <= 50000)
    if (b[t][x] == 1)
      return dp[t][x];
    else
      b[t][x] = 1;
  int ans = 0;
  if (k == t) {
    ans = x / a[t];
  } else {
    if (x > 0) ans = rec(t + 1, x) - rec(t + 1, x / a[t]) + x / a[t];
  }
  if (x <= 50000) dp[t][x] = ans;
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) cin >> a[i];
  sort(a + 1, a + k + 1, greater<long long>());
  cout << n - rec(1, n) << endl;
}
