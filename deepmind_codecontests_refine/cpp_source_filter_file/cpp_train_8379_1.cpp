#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
int main() {
  long long n = 1, k = 1;
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    n %= mod;
    k %= mod;
    n *= 27;
    k *= 7;
  }
  while (n < k) n += mod;
  n -= k;
  cout << n << endl;
}
