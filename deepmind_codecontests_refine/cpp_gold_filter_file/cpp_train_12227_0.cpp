#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double a[500];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  double res = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (m--) {
    int v, u;
    double c;
    cin >> v >> u >> c;
    res = max(res, (a[v] + a[u]) / c);
  }
  printf("%.9lf", res);
}
