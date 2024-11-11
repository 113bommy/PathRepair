#include <bits/stdc++.h>
using namespace std;
unsigned long long n, q;
const unsigned long long maxn = 2e5 + 100, mod = 1e9 + 7;
unsigned long long a[maxn], zero[maxn];
string st;
unsigned long long h[2][maxn], mul[maxn];
bool ask(unsigned long long l1, unsigned long long l2, unsigned long long len) {
  unsigned long long t1 = l1 % 2 == 0 ? 1 : 0;
  unsigned long long t2 = l2 % 2 == 0 ? 1 : 0;
  unsigned long long tmp1 =
      (h[t1][l1 + len - 1] -
       mul[zero[l1 + len - 1] - zero[l1 - 1]] * h[t1][l1 - 1] % mod + mod * 2) %
      mod;
  unsigned long long tmp2 =
      (h[t2][l2 + len - 1] -
       mul[zero[l2 + len - 1] - zero[l2 - 1]] * h[t2][l2 - 1] % mod + mod * 2) %
      mod;
  return tmp1 == tmp2;
}
signed main() {
  cin >> n;
  cin >> st;
  for (unsigned long long i = 1; i <= n; i++) a[i] = st[i - 1] == '0' ? 0 : 1;
  for (unsigned long long i = 1; i <= n; i++) zero[i] = zero[i - 1] + 1 - a[i];
  mul[0] = 1;
  for (unsigned long long i = 1; i <= n; i++) mul[i] = mul[i - 1] * 3 % mod;
  for (unsigned long long i = 1; i <= n; i++)
    if (!a[i]) {
      h[1 - i % 2][i] = (h[1 - i % 2][i - 1] * 3 + 1) % mod,
                h[i % 2][i] = (h[i % 2][i - 1] * 3 + 2) % mod;
    } else
      h[0][i] = h[0][i - 1], h[1][i] = h[1][i - 1];
  cin >> q;
  for (unsigned long long i = 1; i <= q; i++) {
    unsigned long long l1, l2, len;
    cin >> l1 >> l2 >> len;
    cout << (ask(l1, l2, len) ? "Yes" : "No") << endl;
  }
  return 0;
}
