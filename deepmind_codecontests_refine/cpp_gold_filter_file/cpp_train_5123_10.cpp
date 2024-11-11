#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const long long mod = 998244353;
int A[N];
vector<int> G;
inline long long quick_pow(long long x, int p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = (res * x) % mod;
    x = (x * x) % mod, p >>= 1;
  }
  return res;
}
inline long long inv(long long a) {
  long long inv_a = quick_pow(a, mod - 2);
  return inv_a;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    res = 1ll * 100 * (res + 1) % mod * inv(A[i]) % mod;
  }
  cout << res << endl;
}
