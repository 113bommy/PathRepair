#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) {
  long long maxi = max(a, b);
  long long mini = min(a, b);
  while (maxi && mini) {
    long long t = mini;
    mini = maxi % mini;
    maxi = t;
  }
  return max(maxi, mini);
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) {
      res = (res * x);
    }
    x = (x * x);
    y = y >> 1;
  }
  return res;
}
long long ncr(long long x, long long y) {
  long long ans = 1;
  y = (y > x - y ? x - y : y);
  for (long long i = 0; i < y; i++) {
    ans = (ans * (x - i)) % 1000000007;
    ans = (ans * power(i + 1, 1000000007 - 2)) % 1000000007;
    ans = ans % 1000000007;
  }
  return ans;
}
map<pair<int, int>, long long> dp;
long long max_value(int i, int j, long long vals[], long long arr[], int n) {
  if (j == 3) {
    return 0;
  }
  if (i == n) {
    return -5000000000000000000;
  }
  if (dp.find({i, j}) != dp.end()) {
    return dp[{i, j}];
  }
  long long maxi = -5000000000000000000;
  long long a = max_value(i + 1, j, vals, arr, n);
  maxi = max(maxi, a);
  if (j <= 2) {
    long long b = arr[i] * vals[j] + max_value(i + 1, j + 1, vals, arr, n);
    maxi = max(maxi, b);
  }
  if (j <= 1) {
    long long b = arr[i] * (vals[j] + vals[j + 1]) +
                  max_value(i + 1, j + 2, vals, arr, n);
    maxi = max(maxi, b);
  }
  if (j == 0) {
    long long b = arr[i] * (vals[j] + vals[j + 1] + vals[j + 2]) +
                  max_value(i + 1, j + 3, vals, arr, n);
    maxi = max(maxi, b);
  }
  return dp[{i, j}] = maxi;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, p, q, r;
  cin >> n >> p >> q >> r;
  long long arr[n];
  long long vals[] = {p, q, r};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  long long ans = max_value(0, 0, vals, arr, n);
  cout << ans << "\n";
  return 0;
}
