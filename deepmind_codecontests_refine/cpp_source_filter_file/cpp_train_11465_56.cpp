#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int c;
    cin >> c;
    if (c == 0 || c < 4) {
      cout << "N\n";
      continue;
    }
    double sqD = sqrt(c * (c - 4));
    cout << fixed << "Y " << setprecision(9) << (c - sqD) / 2 << " "
         << (c + sqD) / 2 << "\n";
  }
}
