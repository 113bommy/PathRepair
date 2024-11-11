#include <bits/stdc++.h>
using namespace std;
const int N = 200010, mo = 1e9 + 7;
int n, q;
long long a[N], s1[N], s2[N], c[N];
long long qmi(long long a, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * a % mo;
    a = a * a % mo;
    k >>= 1;
  }
  return res;
}
long long mod(long long x) { return (x % mo + mo) % mo; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s1[i] = (s1[i - 1] + a[i]) % mo;
    s2[i] = (s2[i - 1] + a[i] * a[i] % mo) % mo;
    c[i] = (c[i - 1] + i * i % mo) % mo;
  }
  long long l, r, d, len;
  while (q--) {
    cin >> l >> r >> d;
    len = r - l + 1;
    long long f1 = (s1[r] - s1[l - 1]), f2 = (s2[r] - s2[l - 1]);
    f1 = mod(f1), f2 = mod(f2);
    long long f = (f1 * 2 * qmi(len, mo - 2) % mo - (len - 1) * d % mo) % mo *
                  qmi(2, mo - 2) % mo;
    f = mod(f);
    long long ans = f * f % mo * len % mo +
                    f * (len - 1) % mo * len % mo * d % mo +
                    c[len - 1] * d % mo * d % mo;
    ans = mod(ans);
    if (ans == f2)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
