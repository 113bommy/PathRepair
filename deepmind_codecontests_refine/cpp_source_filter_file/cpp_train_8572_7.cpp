#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
using namespace std;
long double EPS = 1e-7;
long long f(int n, int m, int s) {
  if (n % 2 == 0 || m % 2 == 0) return 0;
  if (n * m < s) return 0;
  int S = n * m - s;
  if (S % 4 != 0) return 0;
  S /= 4;
  if (S == 0) {
    long long res = (n - 1) / 2 + 1;
    res *= (m - 1) / 2 + 1;
    res *= 2;
    res--;
    return res;
  }
  long long res = 0;
  for (int i = 1; i * i <= S; i++) {
    if (S % i) continue;
    if (i < n / 2 && S / i < m / 2) res += 2;
    if (i < m / 2 && S / i < n / 2) res += 2;
    if (i * i == S && i < m / 2 && S / i < n / 2) res -= 2;
  }
  return res;
}
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      long long c = f(i, j, s);
      c *= n - i + 1;
      c *= m - j + 1;
      res += c;
    }
  }
  cout << res << endl;
}
