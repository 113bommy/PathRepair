#include <bits/stdc++.h>
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline void sub(long long &a, long long b) {
  a -= b;
  if (a < 0) a += 998244353;
}
inline void add(long long &a, long long b) {
  a += b;
  if (a >= 998244353) a -= 998244353;
}
inline long long mul(long long a, long long b, long long c) {
  return (a * b - (long long)((long double)a * b / c) * c + c) % c;
}
inline long long qp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 998244353;
    a = a * a % 998244353, b >>= 1;
  }
  return ans;
}
inline long long qp(long long a, long long b, long long c) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a, c);
    a = mul(a, a, c), b >>= 1;
  }
  return ans;
}
using namespace std;
const long double pi = acos(-1);
const unsigned long long ba = 233;
const double eps = 1e-8;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 7000 + 10, maxn = 1000000 + 10, inf = 0x3f3f3f3f;
bitset<N> b[100010], f[N], ans[N];
int mu[N];
int main() {
  mu[1] = 1;
  for (int i = 1; i < N; i++)
    for (int j = i << 1; j < N; j += i) mu[j] -= mu[i];
  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j += i) f[j].set(i);
  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j += i)
      if (mu[j / i] != 0) ans[i].set(j);
  int n, q;
  scanf("%d%d", &n, &q);
  while (q--) {
    int op, x, y, z;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 2 || op == 3) scanf("%d", &z);
    if (op == 1)
      b[x] = f[y];
    else if (op == 2)
      b[x] = b[y] ^ b[z];
    else if (op == 3)
      b[x] = b[y] & b[z];
    else
      printf("%d", (b[x] & ans[y]).count() & 1);
  }
  return 0;
}
