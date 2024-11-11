#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> X(n);
  for (int i = 0; i < n; ++i) cin >> X[i];
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  double best = 0.0;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    double cur = 1.0 * (X[a] + X[b]) / c;
    best = max(best, cur);
  }
  cout << fixed << setprecision(10) << best << endl;
}
