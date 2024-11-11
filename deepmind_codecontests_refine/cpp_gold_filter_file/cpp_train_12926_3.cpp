#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) { return a + b - max(a, b); }
long long mulmod(long long a, long long b, long long mod) {
  long long res = 0;
  a = a % mod;
  while (b > 0) {
    if (b % 2 == 1) res = (res + a) % mod;
    a = (a * 2) % mod;
    b /= 2;
  }
  return res % mod;
}
long long mod(long long a, long long b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long solution(vector<long long> A, long long k) {
  long long N = A.size();
  if (k == 0) return 1;
  if (N < k || N < 1 || k < 1) return 0;
  if (N == k) return 1;
  vector<long long> v1(N, 0);
  vector<long long> v2(N, 0);
  vector<long long> v3(N, 0);
  v2[N - 1] = 1;
  v3[A[N - 1] - 1] = 1;
  for (long long i = N - 2; i >= 0; i--) {
    v2[i] = v2[i + 1];
    if (v3[A[i] - 1] == 0) {
      v2[i]++;
      v3[A[i] - 1] = 1;
    }
  }
  if (k == 1) return v2[0];
  for (long long j = 1; j < k; j++) {
    fill(v3.begin(), v3.end(), 0);
    v1[N - 1] = 0;
    for (long long i = N - 2; i >= 0; i--) {
      v1[i] = v1[i + 1];
      v1[i] = v1[i] + v2[i + 1];
      v1[i] = v1[i] - v3[A[i] - 1];
      v3[A[i] - 1] = v2[i + 1];
    }
    v2 = v1;
  }
  return v1[0];
}
long long countSub(string str) {
  vector<long long> last(256, -1);
  long long n = str.length();
  long long dp[n + 1];
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (dp[i]) dp[i] = 2 * dp[i - 1];
    if (dp[i] > 1000000000000) return 100000000000000;
    if (last[str[i - 1]] != -1) dp[i] = dp[i] - dp[last[str[i - 1]]];
    last[str[i - 1]] = (i - 1);
  }
  return dp[n];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, k;
  cin >> n >> k;
  string str;
  cin >> str;
  long long sub;
  sub = countSub(str);
  if (sub < k) {
    cout << -1;
    return 0;
  }
  vector<long long> vec;
  map<char, long long> m1;
  set<char> s1;
  long long cur = 1;
  for (long long i = 0; i < n; i++) {
    if (s1.find(str[i]) == s1.end()) {
      m1[str[i]] = cur;
      cur++;
      vec.push_back(m1[str[i]]);
      s1.insert(str[i]);
    } else {
      vec.push_back(m1[str[i]]);
    }
  }
  long long ctr = 0;
  long long minsum = 0;
  for (long long i = n; i >= 0; i--) {
    long long num = solution(vec, i);
    if (num + ctr < k) {
      ctr += num;
      minsum += num * (n - i);
    } else {
      minsum += (n - i) * (k - ctr);
      break;
    }
  }
  cout << minsum;
}
