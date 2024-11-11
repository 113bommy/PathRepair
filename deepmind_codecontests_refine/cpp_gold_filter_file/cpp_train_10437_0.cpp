#include <bits/stdc++.h>
using namespace std;
const int64_t M = 1e9 + 7;
const int64_t INF = 1e6;
bool prime[INF] = {1};
int64_t d[1000005] = {};
int64_t binpow(int64_t a, int64_t b, int64_t m) {
  a %= m;
  int64_t res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int64_t tot(int64_t n) {
  int64_t result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
int64_t invmd(int64_t n) { return (binpow(n, M - 2, M)); }
void phi_1_to_n(int n) {
  vector<int> phi(n + 1);
  phi[0] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; i++) phi[i] = i;
  for (int i = 2; i <= n; i++) {
    if (phi[i] == i) {
      for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
    }
  }
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool is_prime(int64_t n) {
  if (n == 1) return false;
  int64_t i = 2;
  while (i * i <= n) {
    if (n % i == 0) {
      return false;
    }
    i += 1;
  }
  return true;
}
void SieveOfEratosthenes() {
  prime[1] = 0;
  prime[0] = 0;
  for (int p = 2; p * p <= INF; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= INF; i += p) prime[i] = false;
    }
  }
}
int countteampairs(int a[], int s, int n, map<int, int> m) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] + a[j] <= s) {
        if (m[a[i]] > 0 && m[a[j]] > 0) {
          if (a[i] == a[j] && m[a[i]] < 2) {
            break;
          }
          k++;
          m[a[i]]--;
          m[a[j]]--;
        }
      }
    }
  }
  return k;
}
int64_t div(int64_t n) {
  for (int i = 1; i < 1000005; i++) {
    for (int j = i; j < 1000005; j += i) {
      d[j]++;
    }
  }
}
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) {
      a[i] = abs(a[i]);
    } else
      a[i] = -1 * abs(a[i]);
  }
  for (int i : a) {
    cout << i << " ";
  }
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
