#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
void google(int t) { cout << "Case #" << t << ": "; }
bool per_square(long double a) {
  if (a < 0) return false;
  long long sr = sqrt(a);
  return (sr * sr == a);
}
bool is_prime(long long x) {
  for (long long i = 2; i < sqrt(x) + 1; i++)
    if (x % i == 0) return false;
  return true;
}
long long m = 1e9 + 7;
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2, mod);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == b) return a;
  if (a > b) return gcd(a - b, b);
  return gcd(a, b - a);
}
void solve() {
  long long n;
  cin >> n;
  int dp[n][5];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> dp[i][j];
    }
  }
  vector<set<int>> v(5);
  for (long long i = 0; i < 5; i++) {
    for (long long j = 0; j < n; j++) {
      if (dp[j][i] == 1) {
        v[i].insert(j + 1);
      }
    }
  }
  for (long long i = 0; i < 5; i++) {
    if (v[i].size() >= n / 2) {
      for (long long j = i + 1; j < n; j++) {
        if (v[j].size() >= n / 2) {
          set<int> t;
          for (auto it : v[i]) {
            t.insert(it);
          }
          for (auto it : v[j]) {
            t.insert(it);
          }
          if (t.size() == n) {
            cout << "YES" << '\n';
            return;
          }
        }
      }
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
