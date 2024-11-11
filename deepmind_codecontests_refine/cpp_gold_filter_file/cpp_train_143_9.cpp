#include <bits/stdc++.h>
using namespace std;
template <class T>
inline long long gcd(T x, T y) {
  if (!y) return x;
  return gcd(y, x % y);
}
long long a[5004], c[5004];
const long long VAL = 1000000000;
long long b[5004][5];
int main() {
  long long n, i, j, m;
  cin >> n >> m;
  for (i = 1; i <= n; ++i) a[i] = 1LL << 60;
  for (i = 1; i <= m; ++i) {
    for (j = 1; j <= 4; ++j) cin >> b[i][j];
  }
  for (long long step = m; step; --step) {
    if (b[step][1] == 2) {
      for (i = b[step][2]; i <= b[step][3]; ++i)
        if (a[i] > b[step][4]) a[i] = b[step][4];
    } else {
      for (i = b[step][2]; i <= b[step][3]; ++i) a[i] -= b[step][4];
    }
  }
  memcpy(c, a, sizeof(a));
  for (long long step = 1; step <= m; ++step) {
    if (b[step][1] == 2) {
      long long maxx = -1LL << 60;
      for (i = b[step][2]; i <= b[step][3]; ++i) {
        if (a[i] > maxx) maxx = a[i];
      }
      if (maxx != b[step][4]) {
        cout << "NO\n";
        return 0;
      }
    } else {
      for (i = b[step][2]; i <= b[step][3]; ++i) a[i] += b[step][4];
    }
  }
  cout << "YES\n";
  for (i = 1; i <= n; ++i) cout << min(c[i], VAL) << " ";
  cout << "\n";
  return 0;
}
