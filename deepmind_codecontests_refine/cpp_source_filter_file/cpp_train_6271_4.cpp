#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long min(long long a, long long b) { return a < b ? a : b; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long max3(long long a, long long b, long long c) {
  return max(max(a, b), c);
}
long long max4(long long a, long long b, long long c, long long d) {
  return max(max(a, b), max(c, d));
}
long long min3(long long a, long long b, long long c) {
  return min(min(a, b), c);
}
long long min4(long long a, long long b, long long c, long long d) {
  return min(min(a, b), min(c, d));
}
long long po(long long x, long long n, long long mod = 1000000007) {
  if (n == 0) {
    return 1;
  }
  long long m = po(x, n / 2, mod);
  m *= m;
  m %= mod;
  if (n % 2) {
    m *= x;
    m %= mod;
  }
  return m;
}
long long n, k;
vector<string> v(2005);
vector<string> num{"1110111", "0010010", "1011101", "1011011", "0111010",
                   "1101011", "1101111", "1010010", "1111111", "1111011"};
long long check(string a, string b) {
  long long count = 0;
  for (long long i = 0; i < 7; i++) {
    if (a[i] == '1' && b[i] == '0') {
      return -1;
    } else if (a[i] == '0' && b[i] == '1') {
      count++;
    }
  }
  return count;
}
bool comp(char a, char b) {
  if (b == '-') {
    return 1;
  } else if (a == '-') {
    return 0;
  }
  return a >= b;
}
vector<long long> ans;
long long dp[2005][2005];
bool stored[2005][2005];
long long solve(long long rem, long long index) {
  if (rem < 0) {
    return -1;
  }
  if (stored[rem][index]) {
    return dp[rem][index];
  }
  if (index == n - 1) {
    for (long long j = 9; j >= 0; j--) {
      if (check(v[index], num[j]) == rem) {
        stored[rem][index] = 1;
        ans.push_back(j);
        return dp[rem][index] = 1;
      }
    }
    stored[rem][index] = 1;
    return dp[rem][index] = -1;
  }
  stored[rem][index] = 1;
  for (long long j = 9; j >= 0; j--) {
    if (check(v[index], num[j]) == -1) {
      continue;
    }
    if (solve(rem - check(v[index], num[j]), index + 1) != '-') {
      ans.push_back(j);
      return dp[rem][index] = 1;
    }
  }
  return dp[rem][index] = -1;
}
int32_t main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t startTime = clock();
  cout << fixed << setprecision(12);
  cin >> n >> k;
  for (long long i = 0; i < n; i++) cin >> v[i];
  if (solve(k, 0) == -1) {
    cout << -1;
  } else {
    reverse((ans).begin(), (ans).end());
    for (long long i = 0; i < n; i++) {
      cout << ans[i];
    }
  }
}
