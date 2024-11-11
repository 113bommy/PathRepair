#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[211111];
pair<int, int> d[22][211111];
int gg[211111];
long long sol(int x, int y) {
  if (y - x <= 0) return 0;
  int w = gg[y - x];
  int z = max(d[w][x], d[w][(y - 1) - (1ll << (w)) + 1]).second;
  long long ret = abs(a[z] - a[z + 1]) * 1ll * (z - x + 1) * (y - z);
  ret += sol(x, z);
  ret += sol(z + 1, y);
  return ret;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n - 1; i++) d[0][i] = make_pair(abs(a[i] - a[i + 1]), i);
  gg[1] = 0;
  for (int i = 2; i <= n; i++) gg[i] = gg[i / 2] + 1;
  for (int i = 1; i <= gg[n]; i++)
    for (int j = 0; j + (1ll << (i)) <= n - 1; j++)
      d[i][j] = max(d[i - 1][j], d[i - 1][j + (1ll << (i - 1))]);
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    cout << sol(x, y) << endl;
  }
  return 0;
}
