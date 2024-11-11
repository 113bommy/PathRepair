#include <bits/stdc++.h>
using namespace std;
const long long N = 100005, INF = 2000000000000000000;
long long power(long long a, long long b, long long p) {
  if (a == 0) return 0;
  long long res = 1;
  a %= p;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
vector<long long> prime;
bool isprime[N];
void pre() {
  for (long long i = 2; i < N; i++) {
    if (isprime[i]) {
      for (long long j = i * i; j < N; j += i) isprime[j] = false;
      prime.push_back(i);
    }
  }
  return;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long spf[N + 1];
void spfFun() {
  for (long long i = 0; i <= N; i++) spf[i] = i;
  for (long long i = 2; i * i <= N; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j <= N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}
bool isPerfectSquare(long double x) {
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}
void print(bool n) {
  if (n) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, k;
  cin >> n >> k;
  string s, t;
  cin >> s >> t;
  long long ans = 0, prev = 1;
  for (long long i = 0; i < n; i++) {
    long long curr = 2 * prev + ((long long)(t[i] - s[i]) - 1);
    ans += min(curr, k);
    prev = min(curr, k);
  }
  cout << ans;
}
