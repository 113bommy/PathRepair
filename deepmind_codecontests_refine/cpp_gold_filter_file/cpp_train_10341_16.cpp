#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const long long p = 1e9 + 9;
long long k, pro = 1, S = 0, Ans;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long power(long long a, long long b) {
  long long ans = 1 % p;
  for (; b; b >>= 1) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
  }
  return ans;
}
void work() {
  k = read() / 2;
  long long Now = 0;
  for (register int i = 2; i <= k; i++) {
    pro = pro * (power(2, i) - 3) % p;
    S = (S + (pro * 4 % p)) % p;
  }
  Ans = (10 + (8 * S % p) + (S * S % p * 2 % p)) % p;
  printf("%lld\n", Ans);
}
int main() {
  work();
  return 0;
}
