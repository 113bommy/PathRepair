#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int N = 3e5 + 1000;
long long powmod(long long base, long long exp, long long MOD) {
  long long ans = 1;
  while (exp) {
    if (exp & 1) ans = (ans * base) % MOD;
    base = (base * base) % MOD;
    exp >>= 1;
  }
  return ans;
}
long long modInverse(long long n, long long p) { return powmod(n, p - 2, p); }
void test_case() {
  int n;
  cin >> n;
  if (n & 1)
    cout << 1;
  else
    cout << 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  tt = 1;
  while (tt--) {
    test_case();
  }
  return 0;
}
