#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    long long int l, r, x, y;
    cin >> l >> r;
    if (r - l < l) {
      cout << "-1"
           << "\n";
    } else {
      cout << l << " " << l * 2 << "\n";
    }
  }
  return 0;
}
