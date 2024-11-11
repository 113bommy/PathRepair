#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 69, base = 1024 * 1024, mod = 1e9 + 7;
long long n, k, t[N], rep[N], wynik;
int32_t main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  int licz = 0;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    rep[i] = i + 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (t[i + 1] == 1) rep[i] = rep[i + 1];
  }
  for (int i = 0; i < n; i++) {
    long long p = 1;
    long long second = 0;
    long double huj = 1;
    for (int j = i; j < n; j++) {
      if (t[j] != 1) {
        p *= t[j];
        second += k * t[j];
        huj *= t[j];
        if (huj > 2e18) break;
        if (p == second) wynik++;
        continue;
      }
      int in = rep[j];
      long long ile = in - j;
      if (p > second && (p - second) % k == 0 && second + k * ile >= p) wynik++;
      second += k * ile;
      j = in;
    }
  }
  cout << wynik << "\n";
}
