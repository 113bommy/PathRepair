#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > matmul(vector<vector<long long> > &a,
                                  vector<vector<long long> > &b) {
  int i, j, k, n = a.size();
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      long long temp = 0;
      for (k = 0; k < n; k++)
        temp = (temp + a[i][k] * b[k][j]) % (1000000007LL);
      ans[i][j] = temp;
    }
  return ans;
}
vector<vector<long long> > matpwr(vector<vector<long long> > &a, long long p) {
  int n = a.size();
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (int i = 0; i < n; i++) ans[i][i] = 1;
  while (p) {
    if (p & 1) ans = matmul(ans, a);
    a = matmul(a, a);
    p >>= 1;
  }
  return ans;
}
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long invMod(long long n) { return pwr(n, (1000000007LL) - 2); }
int n, maxSteps, arr[2005], DP[2005];
int dp(int pos, int mid) {
  if (pos == 0) return 0;
  if (DP[pos] != -1) return DP[pos];
  int ans = pos;
  for (int i = pos - 1; i >= 0; i--) {
    if ((long long)abs(arr[i] - arr[pos]) <= (pos - i) * (long long)mid)
      ans = min(ans, (pos - i - 1) + dp(i, mid));
  }
  return DP[pos] = ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> maxSteps;
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long lo = 0, hi = 1e9;
  long long ans = hi;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    memset(DP, -1, sizeof(DP));
    int temp = 2e9;
    for (int i = n - 1; i >= 0; i--) temp = min(temp, (n - 1 - i) + dp(i, mid));
    if (temp <= maxSteps) {
      ans = min(ans, mid);
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ans;
  return 0;
}
