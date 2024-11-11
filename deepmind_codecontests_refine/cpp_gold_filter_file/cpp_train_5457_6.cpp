#include <bits/stdc++.h>
using namespace std;
long long sigma(long long n) { return (n * (n + 1) / 2); }
long long MOD(long long x) {
  if (x >= 0) return x;
  return (-x);
}
bool great(long long a, long long b) { return a > b; }
long long max3(long long a, long long b, long long c) {
  return (max(a, max(b, c)));
}
long long max4(long long a, long long b, long long c, long long d) {
  return (max(max(a, b), max(c, d)));
}
long long min3(long long a, long long b, long long c) {
  return (min(a, min(b, c)));
}
long double min4(long double a, long double b, long double c, long double d) {
  return (min(min(a, b), min(c, d)));
}
vector<long long> factors(long long x) {
  vector<long long> v;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      v.push_back(i);
      if (i != x / i) {
        v.push_back(x / i);
      }
    }
  }
  return v;
}
vector<long long> min_prime;
unordered_map<long long, long long> prime_fact(long long x) {
  unordered_map<long long, long long> mp;
  while (x != 1) {
    mp[min_prime[x]]++;
    x /= min_prime[x];
  }
  return mp;
}
map<long long, long long> factorizee(long long n) {
  map<long long, long long> mp;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if (n != 1) {
    mp[n]++;
  }
  return mp;
}
long long power(long long a, long long b, long long m) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2) {
      ans = (ans * a) % m;
    }
    a = (a * a) % m;
    b = b / 2;
  }
  return ans;
}
long long dp[5003][5003];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  string mat[n];
  for (long long i = 0; i < n; i++) {
    cin >> mat[i];
  }
  for (long long i = 0; i < n; i++) {
    long long j = m - 1;
    while (j >= 0) {
      if (mat[i][j] == '0') {
        dp[i][j] = 0;
        j--;
        continue;
      }
      dp[i][j] = 1;
      long long k = j - 1;
      while (mat[i][k] == '1') {
        dp[i][k] = dp[i][k + 1] + 1;
        k--;
        if (k == -1) {
          break;
        }
      }
      j = k;
    }
  }
  long long ans = 0;
  for (long long i = 0; i < m; i++) {
    vector<long long> xx;
    long long a[5002];
    for (int i = 0; i < 5002; i++) {
      a[i] = 0;
    };
    for (long long j = 0; j < n; j++) {
      a[dp[j][i]]++;
    }
    for (int j = 5001; j > 0; j--) {
      for (long long k = 0; k < a[j]; k++) {
        xx.push_back(j);
      }
    }
    for (long long j = 0; j < xx.size(); j++) {
      ans = max(ans, (j + 1) * xx[j]);
    }
  }
  cout << ans << endl;
}
