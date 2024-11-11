#include <bits/stdc++.h>
using namespace std;
const int mx = 505;
int W[mx], n, m;
long double dens = 0;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> W[i];
  for (int i = 0, a, b, w; i < m; i++) {
    cin >> a >> b >> w;
    dens = max(dens, (long double)(W[a] + W[b]) / w);
  }
  printf("%.6Lf\n", dens);
}
