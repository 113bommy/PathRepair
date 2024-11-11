#include <bits/stdc++.h>
using namespace std;
void speedup() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
int expo(int a, int b, int m) {
  int res = 1;
  while (b) {
    if (b % 2 == 1) res = (res * a) % m;
    a = (a * a) % m;
    b /= 2;
  }
  return res % m;
}
int p[1000003], par[1000002], lp[1000003];
void seiveN() {
  memset(p, 0, sizeof(p));
  long long pn = 0, j;
  for (long long i = 2; i < 1000003; ++i) {
    if (!lp[i]) lp[i] = p[++pn] = i;
    for (j = 1; i * p[j] < 1000003; ++j) {
      lp[i * p[j]] = p[j];
      if (i % p[j] == 0) break;
    }
  }
}
int main() {
  speedup();
  long long n;
  cin >> n;
  long long a[n], i;
  for (i = 0; i <= n - 1; i++) cin >> a[i];
  long long x, d, ans = 0;
  cin >> x >> d;
  for (i = 0; i <= n - 1; i++) {
    long long k = ((long double)a[i] - x) / (x + d);
    ans += (k * d);
    a[i] -= (k * d);
    if (a[i] > x) ans += d;
  }
  cout << ans;
  return 0;
}
