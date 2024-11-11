#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long int l, r;
    cin >> l >> r;
    if (r < 2 * l)
      cout << "-1 -1"
           << "\n";
    else
      cout << l << " " << 2 * l << "\n";
  }
  return 0;
}
