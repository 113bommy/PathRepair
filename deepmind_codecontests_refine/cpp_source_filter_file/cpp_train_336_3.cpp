#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long mod = 10e8 + 7;
  long long n;
  cin >> n;
  long long ans = 1;
  for (int i = 2; i < n + 1; i++) {
    ans *= i % mod;
    ans %= mod;
  }
  long long nonc = 2;
  for (int i = 1; i < n - 1; i++) {
    nonc *= 2 % mod;
    nonc %= mod;
  }
  cout << (ans - nonc) % mod << endl;
  return 0;
}
