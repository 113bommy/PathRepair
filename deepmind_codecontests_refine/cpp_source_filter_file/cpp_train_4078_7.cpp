#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long pow1(long long n, long long p) {
  long long cur = n, res = 1;
  while (p) {
    if (p & 1) {
      (res *= cur) %= MOD;
    }
    p /= 2;
    (cur *= cur) %= MOD;
  }
  return res;
}
int main() {
  long long w, h;
  cin >> w >> h;
  long long res = 4 * pow1(2, h - 1 + w - 1);
  cout << res;
}
