#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long expo(long long a, long long b, long long m) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % m;
    a = (a * a) % m;
    b = b >> 1;
  }
  return res;
}
void extendgcd(long long a, long long b, long long *v) {
  if (b == 0) {
    v[0] = 1;
    v[1] = 0;
    v[2] = a;
    return;
  }
  extendgcd(b, a % b, v);
  long long x = v[1];
  v[1] = v[0] - v[1] * (a / b);
  v[0] = x;
  return;
}
long long mminv(long long a, long long b) {
  long long arr[3];
  extendgcd(a, b, arr);
  return arr[0];
}
long long mminvprime(long long a, long long b) { return expo(a, b - 2, b); }
void swap(long long &x, long long &y) {
  long long temp = x;
  x = y;
  y = temp;
}
long long combination(long long n, long long r, long long m, long long *fact,
                      long long *ifact) {
  long long val1 = fact[n];
  long long val2 = ifact[n - r];
  long long val3 = ifact[r];
  return (((val1 * val2) % m) * val3) % m;
}
void google(long long t) { cout << "Case #" << t << ": "; }
vector<long long> sieve(long long n) {
  long long *arr = new long long[n + 1]();
  vector<long long> vect;
  for (long long i = 2; i <= n; i++)
    if (arr[i] == 0) {
      vect.push_back(i);
      for (long long j = 2 * i; j <= n; j += i) arr[j] = 1;
    }
  return vect;
}
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
long long mod_div(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}
long long phin(long long n) {
  long long number = n;
  if (n % 2 == 0) {
    number /= 2;
    while (n % 2 == 0) n /= 2;
  }
  for (long long i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      number = (number / i * (i - 1));
    }
  }
  if (n > 1) number = (number / n * (n - 1));
  return number;
}
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long dp[201][201][201];
string str;
char ch1, ch2;
long long total_ways(long long idx, long long s, long long k, long long n) {
  if (idx == n) return 0;
  if (dp[idx][s][k] != -1) return dp[idx][s][k];
  long long ans = 0;
  if (ch1 == ch2) {
    if (str[idx] == ch1)
      ans = max(ans, s + total_ways(idx + 1, s + 1, k, n));
    else {
      if (k > 0) ans = max(ans, s + total_ways(idx + 1, s + 1, k - 1, n));
      ans = max(ans, total_ways(idx + 1, s, k, n));
    }
  } else {
    if (str[idx] == ch1) {
      ans = max(ans, total_ways(idx + 1, s + 1, k, n));
      if (k > 0) ans = max(ans, s + total_ways(idx + 1, s, k - 1, n));
    } else if (str[idx] == ch2) {
      ans = max(ans, s + total_ways(idx + 1, s, k, n));
      if (k > 0) ans = max(ans, total_ways(idx + 1, s + 1, k - 1, n));
    } else {
      if (k > 0) {
        ans = max(ans, total_ways(idx + 1, s + 1, k - 1, n));
        ans = max(ans, s + total_ways(idx + 1, s, k - 1, n));
      }
      ans = max(ans, total_ways(idx + 1, s, k, n));
    }
  }
  return dp[idx][s][k] = ans;
}
int32_t main() {
  c_p_c();
  long long n, k;
  cin >> n >> k;
  cin >> str;
  cin >> ch1 >> ch2;
  for (long long i = 0; i <= n; i++) {
    for (long long j = 0; j <= n; j++) {
      for (long long l = 0; l <= k; l++) dp[i][j][l] = -1;
    }
  }
  cout << total_ways(0, 0, k, n) << endl;
}
