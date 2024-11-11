#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  const long long mod = 998244353;
  long long int prod = n;
  long long int sum = prod;
  for (long long int i = n - 1; i > 1; i--) {
    prod = prod * i % mod;
    sum = (sum + prod) % mod;
  }
  sum = (-sum + mod) % mod;
  cout << ((n * prod) % mod + sum) % mod << '\n';
}
