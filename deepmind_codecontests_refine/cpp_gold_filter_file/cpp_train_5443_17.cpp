#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int N = 200005;
const long long int inf = 1e18;
vector<vector<long long int>> adj(N);
bool isprime(long long int n) {
  for (long long int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
long long int factorial(long long int n) {
  return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b) * b);
}
long long int max(long long int a, long long int b) {
  long long int sol = a > b ? a : b;
  return sol;
}
long long int min(long long int a, long long int b) {
  long long int sol = a < b ? a : b;
  return sol;
}
void fun() {}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  fun();
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    if (n * 2 > m)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
  return 0;
}
