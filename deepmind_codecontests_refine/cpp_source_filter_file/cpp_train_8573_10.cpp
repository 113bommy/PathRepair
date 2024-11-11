#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000009;
long long powmod(long long p) {
  long long base = 2, ret = 1;
  while (p) {
    if (p & 1) ret = ret * base % mod;
    p >>= 1;
    base = base * base % mod;
  }
  return ret;
}
int main() {
  long long n, m;
  cin >> n >> m;
  long long total = powmod(m), res = 1;
  while (n--) {
    res = res * total % mod;
    if (res == 0) break;
    --total;
  }
  cout << res << endl;
  return 0;
}
