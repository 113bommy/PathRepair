#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
const int inf = 0x3f3f3f3f;
const long long llinf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
clock_t TIME__START, TIME__END;
void program_end() {}
int n, k;
long long a[N], P = 1, Q;
vector<int> F[N], G, C;
long long fac[N], invfac[N];
void mul(long long &a, int b) { a = (a * b) % MOD; }
void add(long long &a, int b) { a = ((a + b) > MOD ? a + b - MOD : a + b); }
void sub(long long &a, int b) {
  a = ((a - b < 0) ? (a + MOD - b) % MOD : a - b);
}
int ksm(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return ret;
}
void conv(const vector<int> A, const vector<int> B, vector<int> &C) {
  int sza = A.size(), szb = B.size();
  C.resize(0), C.resize(sza + szb - 1);
  for (int i = 0; i < sza; ++i)
    for (int j = 0; j < szb; ++j)
      C[i + j] = ((C[i + j] + 1ll * A[i] * B[j] % MOD) + MOD) % MOD;
}
void workC() {
  C.push_back(a[1]), C.push_back(-1);
  for (int i = 2; i <= n; ++i) {
    vector<int> now;
    now.push_back(a[i]), now.push_back(-1);
    conv(C, now, C);
  }
}
long long downfac(long long i, long long j) {
  long long ret = 1;
  for (int c = 1; c <= j; ++c) mul(ret, i), i--;
  return ret;
}
void workP() {
  long long sum = 0;
  for (int j = 0; j <= n; ++j) {
    long long res = ksm(ksm(n, j), MOD - 2);
    mul(res, downfac(k, j));
    mul(res, C[j]);
    add(sum, res);
  }
  sub(P, sum);
}
inline void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), mul(P, a[i]);
  fac[0] = 1, invfac[0] = 1;
  Q = ksm(n, k);
  workC();
  workP();
  printf("%lld\n", P);
}
int main() {
  TIME__START = clock();
  int Test = 1;
  while (Test--) {
    solve();
  }
  TIME__END = clock();
  program_end();
  return 0;
}
