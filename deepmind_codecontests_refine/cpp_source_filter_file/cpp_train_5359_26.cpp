#include <bits/stdc++.h>
using namespace std;
int n, m;
int b, x, g, y;
bool visb[110], visg[110];
const char ans[][5] = {"YES", "NO"};
bool ok;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  scanf("%d%d", &n, &m);
  scanf("%d", &b);
  for (int i = 0; i < b; i++) {
    scanf("%d", &x);
    visb[x] = 1;
  }
  scanf("%d", &g);
  for (int i = 0; i < g; i++) {
    scanf("%d", &y);
    visg[y] = 1;
  }
  int len = n * m / gcd(n, m);
  for (int i = 0; !ok && i < len; i++)
    if (visb[i % n] || visg[i % m]) visb[i % n] = visg[i % m] = 1;
  for (int i = 0; !ok && i < n; i++)
    if (!visb[i]) ok = 1;
  for (int i = 0; !ok && i < m; i++)
    if (!visg[i]) ok = 1;
  printf("%s", ans[ok]);
  return 0;
}
