#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a == 1 or b == 1)
      cout << "YES\n";
    else if (a == 2 or b == 2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
