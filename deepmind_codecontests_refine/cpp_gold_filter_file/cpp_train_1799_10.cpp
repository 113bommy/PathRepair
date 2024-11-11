#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long int mod = 1000000007;
const double epsilon = 1e-9;
template <class T>
ostream &operator<<(ostream &out, vector<T> &A) {
  for (auto x : A) out << x << " ";
  return out;
}
template <class T>
ostream &operator<<(ostream &out, set<T> &A) {
  for (auto x : A) out << x << " ";
  return out;
}
template <class T>
ostream &operator<<(ostream &out, unordered_set<T> &A) {
  for (auto x : A) out << x << " ";
  return out;
}
template <class T1, class T2>
T1 powr(T1 a, T2 b) {
  T1 res = 1;
  for (long long int i = 1; i < b + 1; i++) res = res * a;
  return res;
}
long long int binpow(long long int a, long long int b) {
  a = a % mod;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return (res + mod) % mod;
}
const long long int N = 10000025;
long long int prime[10000000];
void SieveOfEratosthenes() {
  for (long long int i = 0; i < N; i++) prime[i] = 1;
  prime[0] = 0;
  prime[1] = 0;
  for (long long int p = 2; p * p <= 10000000; p++) {
    if (prime[p] == 1) {
      for (long long int i = p * p; i <= 10000000; i += p) prime[i] = 0;
    }
  }
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int sum = 0, cnt = 0;
    for (long long int i = 1; i < 100000; i++) {
      long long int x = pow(2, i) - 1;
      if (n - (x * (x + 1)) / 2 >= 0) {
        n -= (x * (x + 1) / 2);
        cnt++;
      } else {
        break;
      }
    }
    cout << cnt << "\n";
  }
}
