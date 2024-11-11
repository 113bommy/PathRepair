#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1100000;
const int MOD = 1000000007;
long long n, l, k;
int a[MAX_N];
long long ct1[MAX_N], ct2[MAX_N];
int main() {
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  vector<int> xs(a, a + n);
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int &v : a) {
    v = lower_bound(xs.begin(), xs.end(), v) - xs.begin();
  }
  for (int i = 0; i < n; i++) {
    ct1[a[i]]++;
    if (i < l % n) ct2[a[i]]++;
  }
  int m = xs.size();
  vector<vector<long long>> r1(k + 1, vector<long long>(m)),
      r2(k + 1, vector<long long>(m));
  r1[0][0] = 1, r2[0][0] = 1;
  for (long long i = 1; i <= k; i++) {
    long long sum = 0;
    for (int j = 0; j < m; j++) {
      sum += r1[i - 1][j];
      sum %= MOD;
      r1[i][j] = sum * ct1[j] % MOD;
      r2[i][j] = sum * ct2[j] % MOD;
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= l / n && i <= k; i++) {
    for (int j = 0; j < m; j++) {
      ans += r1[i][j] * ((l / n - i + 1) % MOD) % MOD;
      ans %= MOD;
    }
  }
  for (long long i = 1; i <= ((l - 1) / n + 1) && i <= k; i++) {
    for (int j = 0; j < m; j++) {
      ans += r2[i][j];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}
