#include <bits/stdc++.h>
using namespace std;
void __print(int first) { cerr << first; }
void __print(long first) { cerr << first; }
void __print(long long first) { cerr << first; }
void __print(unsigned first) { cerr << first; }
void __print(unsigned long first) { cerr << first; }
void __print(unsigned long long first) { cerr << first; }
void __print(float first) { cerr << first; }
void __print(double first) { cerr << first; }
void __print(long double first) { cerr << first; }
void __print(char first) { cerr << '\'' << first << '\''; }
void __print(const char *first) { cerr << '\"' << first << '\"'; }
void __print(const string &first) { cerr << '\"' << first << '\"'; }
void __print(bool first) { cerr << (first ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &first) {
  cerr << '{';
  __print(first.first);
  cerr << ',';
  __print(first.second);
  cerr << '}';
}
template <typename T>
void __print(const T &first) {
  int f = 0;
  cerr << '{';
  for (auto &i : first) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
long long check(vector<long long> a, long long n, long long k) {
  long long ans = 0;
  for (long long i = 1; i < n + 1; i++) {
    long long req;
    if (a[i] < 0) {
      req = -1 * a[i];
      ans += req;
      a[i + 1] -= req;
    } else {
      req = a[i] % k;
      if (req < k - req) {
        ans += req;
        a[i + 1] += req;
      } else {
        ans += k - req;
        a[i + 1] -= k - req;
      }
    }
  }
  return ans;
}
bool prime[1000010];
vector<long long> factors;
void sieve(long long n) {
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) factors.push_back(p);
}
int main() {
  sieve(1000000);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n;
  cin >> n;
  vector<long long> a(n + 2);
  long long sum = 0;
  for (long long i = 1; i < n + 1; i++) {
    cin >> a[i];
    sum += a[i];
  };
  vector<long long> prime_divisors;
  for (auto &factor : factors) {
    if (sum % factor == 0) {
      prime_divisors.push_back(factor);
      sum /= factor;
    }
  }
  if (sum != 1) prime_divisors.push_back(sum);
  long long ans = 1e18;
  ;
  for (auto &prime_divisor : prime_divisors) {
    ans = min(ans, check(a, n, prime_divisor));
    ;
  }
  if (ans == 1e18) ans = -1;
  cout << ans << "\n";
}
