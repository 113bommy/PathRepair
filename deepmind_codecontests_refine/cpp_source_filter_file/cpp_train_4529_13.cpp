#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % m;
    b /= 2;
    a = (a * a) % m;
  }
  return ans % m;
}
int a[3 * 100005];
int n, k;
long long dp[1005][1005];
long long solve(int i, int j) {
  if (i == (k - (n % k)) && j == (n % k)) {
    return 0;
  }
  long long ans = (long long)1e17;
  if (dp[i][j] != -1) return dp[i][j];
  if (i < (k - (n % k))) {
    long long sz1 = (n / k);
    long long sz2 = ((n / k) + 1);
    long long id = (i * sz1 + j * sz2);
    ans = min(ans, abs(a[id + sz1 - 1] - a[id]) + solve(i + 1, j));
  }
  if (j < (n % k)) {
    long long sz1 = (n / k);
    long long sz2 = ((n / k) + 1);
    long long id = (i * sz1 + j * sz2);
    ans = min(ans, abs(a[id + sz2 - 1] - a[id]) + solve(i, j + 1));
  }
  return dp[i][j] = ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  memset(dp, -1, sizeof dp);
  cout << solve(0, 0);
}
