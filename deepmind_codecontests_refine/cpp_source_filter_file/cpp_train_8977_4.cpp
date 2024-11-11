#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
using namespace std;
using namespace std;
inline long long int addmod(long long int a, long long int b) {
  return (a % 1000000007 + b % 1000000007) % 1000000007;
}
inline long long int submod(long long int a, long long int b) {
  return (a % 1000000007 - b % 1000000007) % 1000000007;
}
inline long long int mulmod(long long int a, long long int b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
bool isPrime(int n) {
  if (n == 1) return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
vector<int> factors(int n) {
  vector<int> fact;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      fact.push_back(i);
      if (i * i != n) {
        fact.push_back(n / i);
      }
    }
  }
  return fact;
}
long long int pw(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (res * a);
    }
    b = b >> 1;
    a = (a * a);
  }
  return res;
}
void solve(int tt) {
  long long int n;
  cin >> n;
  long long int ans = 0;
  long long int k = log2(n) + 1;
  for (long long int i = 0; i < k; i++) {
    ans = ans + n / pow(2, i);
  }
  cout << ans << "\n";
}
long long int pwmod(long long int a, long long int b) {
  long long int res = 1;
  a = a % 1000000007;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 1000000007;
    }
    b = b >> 1;
    a = (a * a) % 1000000007;
  }
  return res;
}
long long int modinv(long long int a) { return pwmod(a, 1000000007 - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve(tt);
  }
  return 0;
}
