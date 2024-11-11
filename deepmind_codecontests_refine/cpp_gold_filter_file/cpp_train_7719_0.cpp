#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b % 2) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
int ugabuga() {
  int a, b;
  cin >> a >> b;
  if (!b) return cout << 1 << "\n", 0;
  return cout << min(b, a - b) << "\n", 0;
  return cout << ""
              << "\n",
         0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    ugabuga();
  }
}
