#include <bits/stdc++.h>
using namespace std;
long long a[20][20], d[20], f[20][27], res;
int n, m, k, mx;
void nhap() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> d[i];
  for (int i = 1; i <= k; i++) {
    int u, v, x;
    cin >> u >> v >> x;
    a[u - 1][v - 1] = x;
  }
}
int getbit(int x) {
  int tmp = 0;
  for (int i = 0; i < n; i++)
    if ((x >> i) & 1) tmp++;
  return tmp;
}
void ktao() {
  memset(f, 0, sizeof(f));
  mx = 1 << n;
  for (int i = 0; i < mx; i++) {
    int t = getbit(i);
    if (t == 1)
      for (int j = 0; j < n; j++)
        if ((i >> j) & 1) f[j][i] = d[j];
  }
}
void xl() {
  for (int t = 1; t < mx; t++) {
    for (int i = 0; i < n; i++)
      if ((t >> i) & 1 == 1) {
        for (int j = 0; j < n; j++)
          if (((t >> j) & 1) == 0) {
            int v = (1 << j) | t;
            f[j][v] = max(f[j][v], f[i][t] + a[i][j] + d[j]);
          }
      }
  }
  res = 0;
  for (int i = 0; i < mx; i++) {
    int t = getbit(i);
    if (t == m)
      for (int j = 0; j < n; j++) res = max(res, f[j][i]);
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(0);
  nhap();
  ktao();
  xl();
  return 0;
}
