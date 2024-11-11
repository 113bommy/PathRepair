#include <bits/stdc++.h>
using namespace std;
long long n, m, f;
struct M {
  long long t[110][110] = {{0}};
};
M mul(M A, M B) {
  M ans;
  long long i, j, k;
  for (k = 0; k < m; k++)
    for (i = 0; i < m; i++)
      for (j = 0; j < m; j++)
        ans.t[i][j] = (ans.t[i][j] + A.t[i][k] * B.t[k][j]) % 998244353;
  return ans;
}
M qpow(M A, long long x) {
  M ans;
  long long i;
  for (i = 0; i < m; i++) ans.t[i][i] = 1;
  while (x) {
    if (x & 1LL) ans = mul(ans, A);
    A = mul(A, A);
    x >>= 1LL;
  }
  return ans;
}
long long qpow(long long a, long long x) {
  long long ans = 1;
  while (x) {
    if (x & 1LL) ans = ans * a % 998244353;
    a = a * a % 998244353;
    x >>= 1LL;
  }
  return ans;
}
map<long long, long long> mp;
map<long long, long long>::iterator ite;
long long bsgs(long long a, long long t) {
  long long i, x = 1, y, k = ceil(pow(998244353, 0.5));
  for (i = 0; i <= k; i++) {
    mp[t * x % 998244353] = i;
    x = x * a % 998244353;
  }
  x = 1;
  y = qpow(a, k);
  for (i = 0; i < k; i++) {
    ite = mp.find(x);
    if (ite != mp.end()) return ((k * i - ite->second) + 998244353) % 998244353;
    x = x * y % 998244353;
  }
  return -1;
}
void extgcd(long long a, long long b, long long &g, long long &x,
            long long &y) {
  if (b == 0) {
    g = a;
    x = 1;
    y = 0;
    return;
  }
  extgcd(b, a % b, g, y, x);
  y -= a / b * x;
}
long long solve(long long a, long long t) {
  long long rhs = bsgs(3, t), g, x, y;
  extgcd(a, 998244353 - 1, g, x, y);
  if (rhs % g == 0) {
    x = x * (rhs / g) % (998244353 - 1);
    x = (x + 998244353 - 1) % (998244353 - 1);
    return qpow(3, x);
  } else
    return -1;
}
int main() {
  M A;
  long long i;
  scanf("%lld", &m);
  for (i = 0; i < m; i++) scanf("%lld", &A.t[0][i]);
  for (i = 1; i < m; i++) A.t[i][i - 1] = 1;
  scanf("%lld%lld", &n, &f);
  A = qpow(A, n - m);
  printf("%lld", solve(A.t[0][0], f));
}
