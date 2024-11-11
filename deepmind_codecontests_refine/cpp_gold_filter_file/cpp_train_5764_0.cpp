#include <bits/stdc++.h>
using namespace std;
long long modPow(long long r, long long p, long long mod) {
  long long ret = 1;
  long long now = r;
  for (int i = 0; i < (int)40; i++) {
    if ((1LL << i) & p) {
      ret *= now;
    }
    now *= now;
    ret %= mod;
    now %= mod;
  }
  return ret;
}
int main() {
  long long n, m;
  while (cin >> n >> m) {
    cout << (modPow(3, n, m) + m - 1) % m << endl;
  }
  return 0;
}
