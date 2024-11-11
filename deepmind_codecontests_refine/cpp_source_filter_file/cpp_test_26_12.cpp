#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Os")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int Lcm(long long int a, long long int b) {
  return a * (b / gcd(a, b));
}
const int64_t INF = 1e17;
bool allsemchar(string s) {
  return (s.find_first_not_of(s[0]) == string::npos);
}
long long int fuck(long long int n) {
  return (n == 1 || n == 0) ? 1 : n * fuck(n - 1);
}
double value10(double d) { return log10(d); }
long long int combi(long long int n, long long int k) {
  long long int ans = 1;
  k = k > n - k ? n - k : k;
  long long int j = 1;
  for (; j <= k; j++, n--) {
    if (n % j == 0) {
      ans *= (n / j);
    } else if (ans % j == 0) {
      ans = (ans / j * n);
    } else {
      ans = ((ans * n) / j);
    }
  }
  return (ans);
}
long long int digit(long long int n) {
  long long int cnt = 0;
  while (n > 0) {
    n = n / 10;
    cnt++;
  }
  return cnt;
}
void removeChar(char* s, char c) {
  long long int j, n = strlen(s);
  for (long long int i = j = 0; i < n; i++)
    if (s[i] != c) s[j++] = s[i];
  s[j] = '\0';
}
bool areSame(long long int a[], long long int n) {
  unordered_map<long long int, long long int> m;
  for (int i = 0; i < n; i++) m[a[i]]++;
  if (m.size() == 1)
    return true;
  else
    return false;
}
bool palindrom(string s) {
  string u = s;
  reverse(u.begin(), u.end());
  if (s == u) {
    return true;
  } else {
    return false;
  }
}
long long int A_mod_B(string N, long long int a) {
  long long int len = N.size();
  long long int ans = 0;
  for (int i = 0; i < len; i++) ans = (ans * 10 + (int)N[i] - '0') % a;
  return ans % a;
}
vector<bool> SieveofEratosthenes(int n) {
  vector<bool> primes(n + 1, true);
  primes[0] = 0;
  primes[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (primes[i]) {
      for (int j = i * i; j <= n; j += i) {
        primes[j] = false;
      }
    }
  }
  return primes;
}
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    b >>= 1;
    a *= a;
    a %= 1000000007;
    ans %= 1000000007;
  }
  return ans;
}
long long int gcdofarray(long long int a[], long long int n) {
  long long int result = a[0];
  for (long long int i = 1; i < n; i++) {
    result = gcd(a[i], result);
    if (result == 1) {
      return 1;
    }
  }
  return result;
}
void kishor() {
  long long int n;
  cin >> n;
  long long int ans = 1;
  for (int i = 1; i <= 2 * n; i++) {
    ans = (ans * i) % 1000000007;
  }
  cout << ans / 2 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    kishor();
  }
}
