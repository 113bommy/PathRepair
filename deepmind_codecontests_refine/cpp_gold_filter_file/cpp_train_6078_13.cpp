#include <bits/stdc++.h>
using namespace std;
unsigned long long mod = 1000000007;
unsigned long long pow1(unsigned long long a, unsigned long long b) {
  unsigned long long ans = 1;
  while (b) {
    if (b & 1)
      ans = (ans * a) % mod, --b;
    else
      a = (a * a) % mod, b >>= 1;
  }
  return ans;
}
int main() {
  int n, k;
  cin >> n >> k;
  int h = n - k;
  cout << (pow1(k, k - 1) * pow1(h, h)) % mod;
}
