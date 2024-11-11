#include <bits/stdc++.h>
using namespace std;
const long long N = 100005, INF = 2000000000000000000;
const long double EPS = 0.000000000001;
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
bool prime[N] = {true};
long long sum[N] = {0};
void pre() {
  memset(prime, true, sizeof(prime));
  for (long long i = 2; i <= N; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= N; j += i) {
        prime[j] = false;
      }
    }
  }
  for (long long i = 2; i < N; i++) {
    if (prime[i]) sum[i] += i;
    sum[i + 1] = sum[i];
  }
  return;
}
class yup {
 public:
  long long gcd(long long a, long long b) {
    if (a == 0) return b;
    return gcd(b % a, a);
  }
  long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
};
long long minCoins(long long coins[], long long m, long long V) {
  if (V == 0) return 0;
  long long res = INT_MAX;
  for (long long i = 0; i < m; i++) {
    if (coins[i] <= V) {
      long long sub_res = minCoins(coins, m, V - coins[i]);
      if (sub_res != INT_MAX && sub_res + 1 < res) res = sub_res + 1;
    }
  }
  return res;
}
bool com(long long a, long long b) { return a > b; }
long long ans = 0;
class gfg {
 public:
  unsigned long long getFirstSetBitPos(long long n) { return log2(n & -n) + 1; }
};
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n;
  cin >> n;
  char yup[n];
  long long yo[n];
  for (long long i = 0; i < n; i++) {
    cin >> yup[i];
    yo[i] = (long long)(yup[i]) - 48;
  }
  long long a[10];
  for (long long i = 1; i <= 9; i++) {
    cin >> a[i];
  }
  long long pos = -1;
  for (long long i = 0; i < n; i++) {
    if (a[yo[i]] > yo[i]) {
      pos = i;
      yo[i] = a[yo[i]];
      break;
    }
  }
  if (pos != -1) {
    for (long long i = pos + 1; i < n; i++) {
      if (a[yo[i]] >= yo[i]) {
        yo[i] = a[yo[i]];
      } else {
        break;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    cout << yo[i];
  }
}
