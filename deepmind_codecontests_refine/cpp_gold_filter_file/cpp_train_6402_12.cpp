#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
const long double PI = 2 * acos(0.0);
const long double eps = 1e-15;
const int infi = 1e9;
const long long Linfi = (long long)1e18;
const long long MOD = 1000000007;
const int CON = 5;
const int c2 = 37;
int n;
long long gt[2000005];
long long power(long long a, int p) {
  if (p == 0) return 1;
  if (p == 1) return a;
  long long ans = power(a, p / 2);
  ans = (ans * ans) % MOD;
  if (p % 2) ans = (ans * a) % MOD;
  return ans;
}
void solve() {
  gt[0] = 1;
  for (int i = 1; i <= 2000005 - 1; i++) gt[i] = (gt[i - 1] * i) % MOD;
  long long ans = (2 * gt[2 * n - 1]) % MOD;
  long long tmp = (gt[n] * gt[n - 1]) % MOD;
  tmp = power(tmp, MOD - 2);
  ans = ((ans * tmp) - 1 + MOD) % MOD;
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  n++;
  solve();
  return 0;
}
