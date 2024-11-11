#include <bits/stdc++.h>
template <class T>
T read(T &a) {
  a = 0;
  char x = getchar();
  bool f = 0;
  for (; x < '0' || x > '9'; x = getchar()) f |= x == '-';
  for (; x >= '0' && x <= '9'; x = getchar()) a = (a << 3) + (a << 1) + x - '0';
  if (f) a = -a;
  return a;
}
using namespace std;
const long long MOD = 998244353;
int n;
const int N = 3e5 + 5;
long long d[N];
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}
int main() {
  read(n);
  int hn = n;
  n *= 2;
  for (int i = 1; i <= n; ++i) {
    read(d[i]);
  }
  sort(d + 1, d + n + 1);
  long long ans = 0;
  for (int i = 1; i <= hn; ++i) {
    ans -= d[i];
  }
  for (int i = hn + 1; i <= n; ++i) {
    ans += d[i];
  }
  ans %= MOD;
  long long a = 1;
  for (int i = 1; i <= hn; ++i) {
    a = a * i % MOD;
  }
  a = qpow(a, MOD - 2);
  ans = ans * a % MOD;
  for (int i = hn + 1; i <= n; ++i) {
    ans = ans * i % MOD;
  }
  cout << ans << endl;
  return 0;
}
