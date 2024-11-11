#include <bits/stdc++.h>
using namespace std;
const int maxn = 4010, mod = 1e9 + 9;
long long ksm(long long sum, int num) {
  long long ans = 1;
  while (num) {
    if (num & 1) ans = ans * sum % mod;
    sum = sum * sum % mod;
    num >>= 1;
  }
  return ans;
}
int i, j, k, n, m, a, b;
long long jc[maxn], ny[maxn];
long long ans = 0;
void init() {
  jc[0] = 1;
  for (int i = 1; i < maxn; i++) jc[i] = jc[i - 1] * i % mod;
  ny[maxn - 1] = ksm(jc[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--) ny[i] = ny[i + 1] * (i + 1) % mod;
}
long long C(int A, int B) {
  if (B > A) return 0;
  return jc[A] * ny[B] % mod * jc[A - B] % mod;
}
long long make(int A, int B) { return C(A - 1, B - 1) % mod; }
int main() {
  cin >> n >> a >> b;
  init();
  for (i = 2; i < n; i++)
    for (j = i; j < n; j++) {
      int lenb = (j - i) + 1, lena = n - lenb;
      ans += make(b, lenb) * make(a, lena) % mod;
      ans %= mod;
    }
  cout << ans * (jc[a] * jc[b] % mod) % mod << endl;
  return 0;
}
