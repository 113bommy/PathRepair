#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using db = double;
const ll mod = 1E9 + 7;
int n, m;
ll a[1 << 20];
void fwt(ll *a, int n, int op = 1) {
  for (int i = 1; i < n; i *= 2)
    for (int j = 0; j < n; j += i * 2)
      for (int k = 0; k < i; ++k) {
        ll x = a[j + k], y = a[j + k + i];
        a[j + k] = x + y, a[j + k + i] = x - y;
        if (op == -1) a[j + k] /= 2, a[j + k + i] /= 2;
      }
}
char s[(1 << 20) + 6];
int main() {
  cin >> m;
  n = 1 << m;
  scanf("%s", s);
  for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
  fwt(a, n);
  for (int i = 0; i < n; ++i) a[i] *= a[i];
  fwt(a, n, -1);
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    (ans += a[i] << (m - __builtin_popcount(i))) %= mod;
  cout << ans * 3 % mod << endl;
  return 0;
}
