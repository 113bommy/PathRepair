#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int d[1000020];
long long ln, z, w;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    d[x]++, d[y]++;
  }
  ln = n;
  z = ln * (ln - 1) * (ln - 2) / 6;
  for (int i = 0; i < n; i++) {
    w += d[i] * (ln - d[i] - 1);
  }
  w /= 2;
  cout << z - w;
}
