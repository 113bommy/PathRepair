#include <bits/stdc++.h>
using namespace std;
long long int Powerm(long long int a, long long int b, long long int m) {
  if (b == 0) return 1;
  if (b == 1) return a % m;
  long long int t = Powerm(a, b / 2, m);
  t = (t * t) % m;
  if (b & 1) t = (t * a) % m;
  return t;
}
long long int Power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int t = Power(a, b / 2);
  t = (t * t);
  if (b & 1) t = (t * a);
  return t;
}
long long int Gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return Gcd(b, a % b);
  }
}
long long int LeftMostSetBit(long long int n) {
  if (n == 0) {
    return 0;
  }
  long long int msb = 0;
  while (n != 0) {
    n = n / 2;
    msb++;
  }
  return msb;
}
long long int RightMostSetBit(long long int n) { return __builtin_ffsl(n); }
long long int LLsqrt(long long int x) {
  if (x == 0 || x == 1) return x;
  long long int start = 1, end = x / 2, ans;
  while (start <= end) {
    long long int mid = (start + end) / 2;
    if (mid * mid == x)
      return mid;
    else if (mid <= x / mid)
      ans = mid, start = mid + 1;
    else
      end = mid - 1;
  }
  return ans;
}
void input() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
long long int dp[71][71][35][71];
long long int a[71][71];
long long int n, m, k;
long long int solve(long long int i, long long int j, long long int cnt,
                    long long int rem) {
  if (i >= n) {
    if (rem == 0) {
      return 0;
    } else {
      return INT_MIN;
    }
  }
  if (dp[i][j][cnt][rem] != -1) {
    return dp[i][j][cnt][rem];
  }
  long long int ans = INT_MIN;
  if (j >= m) {
    return solve(i + 1, 0, m / 2, rem);
  }
  if (cnt > 0) {
    ans = max(ans, solve(i, j + 1, cnt - 1, (rem + a[i][j] + k) % k) + a[i][j]);
  }
  ans = max(ans, solve(i, j + 1, cnt, rem));
  return dp[i][j][cnt][rem] = ans;
}
int main() {
  input();
  cin >> n >> m >> k;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0][0][0] = 0;
  cout << solve(0, 0, m / 2, 0) << endl;
}
