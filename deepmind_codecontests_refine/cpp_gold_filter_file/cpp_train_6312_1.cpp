#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long quick_pow(long long a, long long b) {
  long long ans = 1, tmp = a;
  while (b) {
    if (b & 1) ans = ans * tmp % mod;
    tmp = tmp * tmp % mod;
    b >>= 1;
  }
  return ans;
}
std::map<int, int> mp;
long long solve(int x) {
  if (x == 1) return 1;
  if (mp.count(x)) return mp[x];
  mp[x] = quick_pow(2, x - 1);
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      mp[x] = (mp[x] - solve(x / i) + mod) % mod;
      if (i != x / i) {
        mp[x] = (mp[x] - solve(i) + mod) % mod;
      }
    }
  }
  mp[x] = (mp[x] - solve(1) + mod) % mod;
  return mp[x];
}
int main() {
  int x, y;
  cin >> x >> y;
  if (y % x != 0) {
    printf("0\n");
    return 0;
  }
  cout << solve(y / x) << endl;
  return 0;
}
