#include <bits/stdc++.h>
long long exp(long long x, long long y, long long p) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % p) % p;
    x = (x * x) % p;
    y /= 2;
  }
  return res;
}
long long expo(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % ((long long)1e9 + 7)) % ((long long)1e9 + 7);
    x = (x * x) % ((long long)1e9 + 7);
    y /= 2;
  }
  return res;
}
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  {
    long long n, aa, i, x;
    cin >> n >> aa;
    long long mas = 0;
    long long f[1000006] = {0};
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == aa)
        mas++;
      else {
        if (f[a[i]] <= aa) f[a[i]]++;
      }
    }
    for (i = 1; i < 1000006; i++)
      if (f[i] >= mas && i != aa) {
        cout << i << "\n";
        return 0;
      }
    cout << -1 << "\n";
  }
  return 0;
}
