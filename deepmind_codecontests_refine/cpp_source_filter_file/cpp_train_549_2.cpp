#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, f, c;
  double t;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> v1 >> v2 >> t >> f >> c;
  double S = t * v1 + ((t * v1) / (v2 - v1)) * v1;
  double D = S;
  int ans = 0;
  if (v1 > v2) {
    cout << 0;
    return 0;
  }
  while (S < c) {
    ++ans;
    S += (2 * S / v2 + f) * v1 + (S - D) / (v2 - v1) * v1;
    D = S;
  }
  cout << ans;
}
