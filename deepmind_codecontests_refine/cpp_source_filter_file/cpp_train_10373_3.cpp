#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[1001], f[1001][1001], bell[1001], x;
map<long long, int> k;
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%1lld", &x), a[j] |= (x << i);
  for (int i = 0; i < m; i++) k[a[i]]++;
  f[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    f[i][0] = f[i - 1][i - 1];
    for (int j = 1; j <= i; j++)
      f[i][j] = (f[i][j - 1] * j + f[i - 1][j - 1]) % 1000000007;
  }
  long long ans = 1;
  for (map<long long, int>::iterator i = k.begin(); i != k.end(); i++)
    ans = ans * f[(*i).second][0] % 1000000007;
  printf("%lld", ans);
  return 0;
}
