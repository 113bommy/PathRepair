#include <bits/stdc++.h>
using namespace std;
long long sum_mod(long long a, long long b) { return (a + b) % 1000000007; }
long long subtract_mod(long long a, long long b) {
  return (a % 1000000007 - b % 1000000007 + 1000000007) % 1000000007;
}
long long multiply_mod(long long a, long long b) {
  return (a % 1000000007 * b % 1000000007) % 1000000007;
}
long long modInverse(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long divide_mod(long long a, long long b) {
  return (a * modInverse(b, 1000000007 - 2)) % 1000000007;
}
long long gcd(long long a, long long b) {
  while (b) swap(a %= b, b);
  return a;
}
bool check(vector<long long> nums, long long m, long long t) {
  long long j = 0;
  for (long long i = 1; i <= m; ++i) {
    long long k = t;
    k -= (j + 1);
    while (k > 0 && j < nums.size()) {
      if (nums[j] <= k)
        k -= nums[j], nums[j] = 0, j++, k--;
      else
        nums[j] -= k, k = 0;
    }
    while (j < nums.size() && nums[j] == 0) j++;
    if (j == nums.size()) return true;
  }
  return false;
}
int main() {
  long long n, m;
  cin >> n >> m;
  vector<long long> nums(n);
  long long r = 0;
  for (long long i = 0; i < n; ++i) cin >> nums[i], r += nums[i];
  r += n;
  long long l = 0;
  while (l < r) {
    long long md = l + (r - l) / 2;
    if (check(nums, m, md))
      r = md;
    else
      l = md + 1;
  }
  cout << l << endl;
}
