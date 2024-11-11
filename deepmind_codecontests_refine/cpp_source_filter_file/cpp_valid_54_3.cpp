#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
long long ans, t, n, k;
const int N = 2e5 + 5;
long long p[N];
void solve0() {
  long long ans = 0, cur = 1;
  for (int i = k; i >= 1; i--) {
    ans = (ans + cur * ksm(p[k - 1], n) % mod) % mod;
    cur = cur * (p[n - 1] - 1) % mod;
  }
  cout << (ans + cur) % mod << endl;
}
void solve1() {
  long long ans = 0, cur = 1;
  for (int i = k; i >= 1; i--) {
    cur = cur * (p[n - 1] + 1) % mod;
  }
  cout << cur << endl;
}
int main() {
  p[0] = 1;
  for (int i = 1; i < N; i++) p[i] = p[i - 1] * 2 % mod;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ans = 0;
    if (k == 0) {
      cout << 0 << endl;
      continue;
    }
    if (n % 2 == 0)
      solve0();
    else
      solve1();
  }
  return 0;
}
