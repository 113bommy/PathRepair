#include <bits/stdc++.h>
using namespace std;
const int MAXN = 212345;
const int INF = 0x3f3f3f3f;
const long long MOD = 1000000007;
long long n, m, k;
long long x, s;
long long a[MAXN], b[MAXN], c[MAXN], d[MAXN];
long long resp;
int main() {
  cin >> n >> m >> k;
  cin >> x >> s;
  resp = n * x;
  for (int i = 1; i <= m; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 1; i <= k; i++) cin >> c[i];
  for (int i = 1; i <= k; i++) cin >> d[i];
  for (int i = 1; i <= m; i++) {
    if (b[i] <= s) {
      long long ini = 1, fim = k, r = s - b[i];
      while (ini < fim) {
        long long meio = (ini + fim + 1) / 2;
        if (d[meio] <= r)
          ini = meio;
        else
          fim = meio - 1;
      }
      if (d[ini] <= r) {
        if (n >= c[ini])
          resp = min(resp, a[i] * (n - c[ini]));
        else
          resp = 0;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (b[i] <= s) resp = min(resp, a[i] * n);
  }
  for (int i = 1; i <= k; i++) {
    if (d[i] <= s) resp = min(resp, x * (n - c[i]));
  }
  cout << resp << '\n';
}
