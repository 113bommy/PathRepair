#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
using namespace std;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG = 60;
int n, m, k, u, v, x, y, t, a, b;
long long A[MAXN], ans, fix, X;
long long g[MAXN];
bitset<MAXN> B[LOG], C;
bool check(long long num, long long fix) {
  vector<long long> vec;
  for (int i = 0; i < LOG; i++) {
    long long x = g[i] & fix;
    for (long long a : vec)
      if (a & -a & x) x ^= a;
    if (!x) continue;
    for (long long &a : vec)
      if (x & -x & a) a ^= x;
    vec.push_back(x);
  }
  for (long long a : vec)
    if (a & -a & num) num ^= a;
  return (num == 0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    X ^= A[i];
    long long x = A[i];
    for (int j = LOG - 1; ~j; j--) x = min(x, x ^ g[j]);
    if (!x) continue;
    x = A[i];
    C.reset();
    C.set(i);
    for (int j = LOG - 1; ~j; j--)
      if (x > (x ^ g[j])) {
        x ^= g[j];
        C ^= B[j];
      }
    int bit = 63 - __builtin_clzll(x);
    g[bit] = x;
    B[bit] = C;
  }
  for (int i = LOG - 1; ~i; i--)
    if (!(((X) >> (i)) & 1)) {
      fix |= (1ll << i);
      if (check(ans | (1ll << i), fix)) ans |= (1ll << i);
    }
  for (int i = LOG - 1; ~i; i--)
    if ((((X) >> (i)) & 1)) {
      fix |= (1ll << i);
      if (!check(ans, fix)) ans |= (1ll << i);
    }
  cerr << "ans" << '=' << (ans) << endl;
  C.reset();
  for (int j = LOG - 1; ~j; j--)
    if (ans > (ans ^ g[j])) {
      ans ^= g[j];
      C ^= B[j];
    }
  for (int i = 1; i <= n; i++) cout << 1 + C[i] << " \n"[i == n];
  return 0;
}
