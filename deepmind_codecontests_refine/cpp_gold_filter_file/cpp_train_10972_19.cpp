#include <bits/stdc++.h>
using namespace std;
template <typename T>
T mabs(const T &a) {
  return a < 0 ? -a : a;
}
bool check(long long n, long long m, long long k, long long cnt) {
  m -= cnt * k;
  long long left = n - cnt * k;
  long long can = left / k * (k - 1) + left % k;
  return can >= m;
}
const int mod = 1e9 + 9;
long long toPow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
void run() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long l = 0, r = m / k;
  long long res = 0;
  while (l <= r) {
    long long c = (l + r) >> 1;
    if (check(n, m, k, c)) {
      res = c;
      r = c - 1;
    } else
      l = c + 1;
  }
  long long score = 0;
  if (res > 0) score = (toPow(2, res + 1) - 2) * k % mod;
  score = (score + m - res * k) % mod;
  score = (score + mod) % mod;
  cout << score << endl;
}
int main() {
  run();
  return 0;
}
