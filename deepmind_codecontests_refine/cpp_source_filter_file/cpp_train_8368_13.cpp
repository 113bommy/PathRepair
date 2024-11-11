#include <bits/stdc++.h>
using namespace std;
const int maxn = 111;
const int MOD = 1000000007;
long long f[maxn];
int n;
string x;
long long pw[maxn];
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 100; i++) {
    pw[i] = pw[i - 1] * 2 % MOD;
  }
  while (cin >> x) {
    n = x.length();
    f[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (x[i] == '0') f[i] = 2 * f[i + 1];
      if (x[i] == '1') f[i] = 2 * f[i + 1] + pw[2 * (n - i - 1)];
      f[i] %= MOD;
    }
    cout << f[0] << endl;
  }
  return 0;
}
