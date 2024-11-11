#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    if (a == b) {
      if (a == 0)
        cout << 0 << "\n";
      else
        cout << 1 << "\n";
    } else if (abs(a - b) % 2 == 0)
      cout << 2 << "\n";
    else
      cout << -1 << "\n";
  }
  return 0;
}
