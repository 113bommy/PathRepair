#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m, dx, dy;
int d[1000005];
int p[1000005];
int main() {
  scanf("%d%d%d%d", &n, &m, &dx, &dy);
  memset(d, 0, sizeof(d));
  int a = 0, b = 0;
  d[0] = 0;
  while (1) {
    a = (a + dx) % n;
    b = (b + dy) % n;
    if (a == 0 && b == 0) break;
    d[a] = b;
  }
  memset(p, 0, sizeof(p));
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a, &b);
    int u = b - d[a];
    p[(u + n) % n]++;
  }
  int ans = 0;
  int k;
  for (int i = 0; i < n; i++) {
    if (p[i] > ans) {
      ans = p[i];
      k = i;
    }
  }
  cout << 0 << " " << k;
  return 0;
}
