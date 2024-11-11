#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005, maxl = 320, mo = int(1e9) + 7;
int cf[maxn];
int f[maxl][maxn], fac[maxn], rfac[maxn], p26[maxn], rp[maxn], p25[maxn], n;
int get_c(int n, int m) {
  return fac[n] * 1ll * rfac[m] % mo * rfac[n - m] % mo;
}
int pow(int a, int b) {
  int tmp = 1;
  for (; b; b >>= 1, a = a * 1ll * a % mo)
    if (b & 1) tmp = tmp * 1ll * a % mo;
  return tmp;
}
void pre_treat() {
  int n = maxn - 5;
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * 1ll * i % mo;
  rfac[n] = pow(fac[n], mo - 2);
  for (int i = n; i; i--) rfac[i - 1] = rfac[i] * 1ll * i % mo;
  p26[0] = 1, p25[0] = 1;
  for (int i = 1; i <= n; i++)
    p26[i] = p26[i - 1] * 26ll % mo, p25[i] = p25[i - 1] * 25ll % mo;
  for (int i = 0; i <= n; i++) rp[i] = pow(p26[i], mo - 2);
  for (int l = 1; l < maxl; l++)
    for (int n = l; n <= maxn - 5; n++)
      f[l][n] = (f[l][n - 1] +
                 get_c(n - 1, l - 1) * 1ll * p25[n - l] % mo * rp[n] % mo) %
                mo;
}
void calc(int l) {
  cf[l - 1] = 0;
  for (int n = l; n <= maxn - 5; n++)
    cf[n] =
        (cf[n - 1] + get_c(n - 1, l - 1) * 1ll * p25[n - l] % mo * rp[n] % mo) %
        mo;
}
int main() {
  pre_treat();
  int m;
  cin >> m;
  string s;
  cin >> s;
  int cl = s.length();
  if (cl >= maxl) calc(cl);
  for (; m; m--) {
    int t;
    cin >> t;
    if (t == 1) {
      cin >> s;
      cl = s.length();
      if (cl >= maxl) calc(cl);
    } else {
      int n;
      cin >> n;
      if (n < cl) {
        cout << 0 << endl;
        continue;
      }
      if (cl >= maxl)
        cout << cf[n] * 1ll * p26[n] % mo << endl;
      else
        cout << f[cl][n] * 1ll * p26[n] % mo << endl;
    }
  }
  return 0;
}
