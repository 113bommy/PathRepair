#include <bits/stdc++.h>
using namespace std;
int n, m, V[1010][1010];
long long mod = 10;
long long pow2(int step) {
  long long r = 1;
  while (step-- > 0) {
    r = (2 * r) % mod;
  }
  return r;
}
int main() {
  bool OK = false;
  int i, j, k, x, y, z;
  cin >> n >> m >> k;
  if (n % 2 == m % 2) {
    cout << 0 << '\n';
    return 0;
  }
  for (i = 0; i < k; ++i) {
    cin >> x >> y >> z;
    x--;
    y--;
    V[x][y] = z;
  }
  cin >> mod;
  long long ANS = 1;
  if (n >= m) {
    for (i = 0; i < n; ++i) {
      k = 0;
      z = 1;
      for (j = 0; j < m; ++j)
        if (V[i][j] == 0)
          ++k;
        else
          z *= V[i][j];
      if (k == 0 && z != -1) ANS = 0;
      if (k == m && !OK) {
        OK = true;
        continue;
      }
      if (k > 0) ANS = (ANS * pow2(k - 1)) % mod;
    }
  } else {
    for (j = 0; j < m; ++j) {
      k = 0;
      z = 1;
      for (i = 0; i < n; ++i)
        if (V[i][j] == 0)
          ++k;
        else
          z *= V[i][j];
      if (k == 0 && z != -1) ANS = 0;
      if (k == n && !OK) {
        OK = true;
        continue;
      }
      if (k > 0) ANS = (ANS * pow2(k - 1)) % mod;
    }
  }
  if (!OK) ANS = 0;
  cout << ANS << '\n';
  return 0;
}
