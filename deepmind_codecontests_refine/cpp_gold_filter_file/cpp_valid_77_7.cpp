#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 5;
long long f[maxn] = {};
int main() {
  int q = 1;
  while (q--) {
    long long n, m;
    cin >> n >> m;
    f[1] = 1;
    f[2] = 2;
    for (int i = 2; i <= n; i++) {
      if (i == 2)
        f[i] = 2;
      else
        f[i] = (f[i] + 2 * f[i - 1] + 1) % m;
      long long x = f[i] - f[i - 1];
      for (int j = i * 2; j <= n; j += i) f[j] = (f[j] + x) % m;
    }
    cout << (f[n] % m + m) % m << endl;
  }
  return 0;
}
