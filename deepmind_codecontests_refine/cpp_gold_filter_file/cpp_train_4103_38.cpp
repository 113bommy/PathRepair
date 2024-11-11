#include <bits/stdc++.h>
using namespace std;
struct TEdge {
  long x;
  long y;
};
long n, m, k, res;
long f[2000];
TEdge e[2000];
int main() {
  scanf("%ld%ld%ld", &n, &m, &k);
  for (long i = 1; i <= n; i++) scanf("%ld%ld", &e[i].x, &e[i].y);
  for (long i = 1; i <= n; i++) f[e[i].x] = 1000000000;
  for (long i = 1; i <= n; i++) f[e[i].x] = min(f[e[i].x], e[i].y);
  for (long i = 1; i <= m; i++) res += f[i];
  printf("%ld", min(res, k));
}
