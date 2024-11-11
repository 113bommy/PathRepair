#include <bits/stdc++.h>
using namespace std;
int n;
long long a[5][100007], f[100007][5];
long long sum(int i, int j1, int j2) {
  if (j1 > j2) swap(j1, j2);
  long long res = 0LL;
  for (int j = j1; j <= j2; j++) res += a[j][i];
  return res;
}
int main() {
  cin >> n;
  for (int i = 0; i < 3; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  f[0][0] = 0;
  f[0][1] = -10000000000000000LL;
  f[0][2] = -10000000000000000LL;
  f[0][3] = -10000000000000000LL;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 4; j++) f[i][j] = -10000000000000000LL;
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        f[i][k] = max(f[i][k], f[i - 1][j] + sum(i, j, k));
    long long al = sum(i, 0, 2);
    for (int j : {0, 2}) {
      f[i][3] = max(f[i][3], f[i - 1][j] + al);
      f[i][j] = max(f[i][j], f[i - 1][3] + al);
    }
  }
  cout << f[n][2];
}
