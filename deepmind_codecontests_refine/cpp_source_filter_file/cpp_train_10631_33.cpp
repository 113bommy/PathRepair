#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6;
int power(int a, int b) {
  int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n;
  cin >> n;
  cout << n + 1 << "\n";
  cout << 2 << " " << n << " " << 1 << "\n";
  cout << 1 << " " << n << " " << N << "\n";
  for (int i = 1; i < n; i++) cout << 1 << " " << i << " " << N - i << "\n";
  return 0;
}
