#include <bits/stdc++.h>
using namespace std;
int n, m, k, p;
map<int, int> row[1001];
int prod[1001], C[1001][1001];
int pow(int a, int n) {
  int ret = 1;
  while (n)
    if (n & 1)
      n--, ret = (long long)ret * a % p;
    else
      n >>= 1, a = (long long)a * a % p;
  return ret;
}
int calc(int n, int prod) {
  int ret = 0;
  for (int i = (0); i <= (n); i++)
    if (i % 2 == 1 && prod == -1 || i % 2 == 0 && prod == 1)
      ret = (ret + C[n][i]) % p;
  return ret;
}
int main() {
  cin >> n >> m >> k;
  if ((n + m) & 1) return puts("0"), 0;
  for (int x = (1); x <= (n); x++) prod[x] = 1;
  for (int i = (1); i <= (k); i++) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    if (n < m) swap(x, y);
    prod[x] *= c;
    row[x][y] = c;
  }
  if (n < m) swap(n, m);
  cin >> p;
  for (int i = (0); i <= (1000); i++) C[i][0] = 1;
  for (int i = (1); i <= (1000); i++)
    for (int j = (1); j <= (i); j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
  bool flag = 1;
  int ans = 1;
  for (int x = (1); x <= (n); x++) {
    if (flag && !((int)(row[x]).size())) {
      flag = 0;
      continue;
    }
    if (row[x][m]) {
      ans = (long long)ans * calc(m - ((int)(row[x]).size()), -prod[x]) % p;
    } else {
      ans = (long long)ans * pow(2, m - 1 - ((int)(row[x]).size()) + 1) % p;
    }
  }
  cout << ans << endl;
  return 0;
}
