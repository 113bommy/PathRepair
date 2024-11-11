#include <bits/stdc++.h>
using namespace std;
const int N(2010), MOD(1000000007);
int n, x, y;
int a[N];
long long f[N][N];
bool b1[N], b2[N];
int main() {
  cin >> n;
  for (int i = int(1); i < int(n + 1); ++i) {
    cin >> a[i];
    if (a[i] == -1) {
      b1[i] = true;
      ++x;
    } else
      b2[a[i]] = true;
  }
  for (int i = int(1); i < int(n + 1); ++i)
    if (b1[i] && b2[i]) ++y;
  f[0][0] = 1;
  f[1][0] = 0;
  f[1][1] = 1;
  for (int i = int(2); i < int(x + 1); ++i) {
    f[i][0] = (i - 1) * (f[i - 2][0] + f[i - 1][0]) % MOD;
    for (int j = int(1); j < int(min(i, y) + 1); ++j) {
      if (i != j)
        f[i][j] = (j * f[i - 1][j] + (i - 1 - j) * f[i - 1][j + 2]) % MOD;
      else
        f[i][j] = i * f[i - 1][j - 1] % MOD;
    }
  }
  cout << f[x][y] << endl;
  return 0;
}
