#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const int M = 2e5;
const int oo = 1e9;
const int mod = 998244353;
long long FP(long long a, long long b) {
  if (!b) return 1;
  long long ret = FP(a, b / 2);
  if (b % 2) return ((ret * ret) % mod * a) % mod;
  return (ret * ret) % mod;
}
int main() {
  int n, m, a;
  cin >> n >> m >> a;
  long long ans = 1;
  int lst = 0;
  for (int i = 0; i < m; i++) {
    int b;
    cin >> b;
    int dif = b - lst;
    long long cnt = FP(a, 2 * dif);
    long long cnt2 = FP(a, dif);
    cnt = (cnt + cnt2) % mod;
    ans = (ans * ((cnt * FP(2, mod - 2)) % mod)) % mod;
    lst = b;
  }
  lst = n - lst * 2;
  ans = (ans * FP(a, lst)) % mod;
  cout << ans << endl;
}
