#include <bits/stdc++.h>
using namespace std;
long long mod;
int cal(long long a) {
  int ans = 0;
  while (a) {
    ans += a % 10;
    a /= 10;
  }
  return ans % mod;
}
int sol(int n) {
  long long ans = 0;
  for (int i = 0; i <= n; i++) ans += cal(i);
  return ans;
}
long long T = 1e17;
int main() {
  long long n;
  cin >> mod;
  n = mod;
  n -= 5 * (18 * (9 * T % mod) % mod) % mod;
  cout << n << ' ' << n + T * 10 - 1 << endl;
  return 0;
}
