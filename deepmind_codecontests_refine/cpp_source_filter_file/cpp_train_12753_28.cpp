#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, p, q;
  cin >> l >> p >> q;
  float t = float(l) / float(p + q);
  float ans = float(p) * float(t);
  cout << setprecision(4) << ans << "\n";
}
