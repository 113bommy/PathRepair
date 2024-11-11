#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int N = 1000009;
const int logN = 22;
const int sqrN = 450;
const int MOD = 1000000009;
const int INF = 1e9;
const long long INF64 = 1e18;
const long double PI = 3.1415926535897932384626433832795;
const long double eps = 1e-9;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n;
long long resL2[N];
long long p2[N];
long long d;
long long up[N];
void calc_L2() {
  p2[0] = 1;
  for (int i = 0; i < (int)(N); ++i)
    if (i) p2[i] = (p2[i - 1] * 2LL) % MOD;
  long long res = 1;
  for (int i = 1; i < N; ++i) {
    res = (res + 2LL * p2[i]) % MOD;
    resL2[i] = res;
  }
  for (int i = 0; i < (int)(5); ++i) up[i] = 1;
  for (int i = 6; i < N; i += 2) {
    up[i] = (up[i - 2] * resL2[(i - 4) / 2]) % MOD;
  }
}
bool need = true;
long long calcL2(int pos) {
  if (need) {
    calc_L2();
    need = false;
  }
  return resL2[(pos - 2) / 2];
}
long long calcL(int pos) {
  if (pos == n) return 2;
  if (pos & 1) return ((2 + calcL(pos + 1)) % MOD);
  if (pos == 2) return ((2 + calcL(pos + 1)) % MOD);
  return ((2 + calcL2(pos) * calcL(pos + 1)) % MOD);
}
long long calcR(int pos) {
  if (pos == n) return (d * up[pos]) % MOD;
  if (pos == 1) return ((d + calcR(pos + 1)) % MOD);
  if (pos == 2 || pos == 3) return ((2LL * d + calcR(pos + 1)) % MOD);
  if (pos & 1) return (((2LL * d * up[pos + 1]) % MOD + calcR(pos + 1)) % MOD);
  return (((d * up[pos]) % MOD + (d * up[pos + 2]) % MOD + calcR(pos + 1)) %
          MOD);
}
int main() {
  srand(time(NULL));
  cout << setprecision(10) << fixed;
  cerr << setprecision(10) << fixed;
  cin >> n;
  calc_L2();
  long long ans = 1;
  d = calcL(2);
  ans = (ans + calcR(1)) % MOD;
  cout << (2ll * ans) % MOD;
  return 0;
}
