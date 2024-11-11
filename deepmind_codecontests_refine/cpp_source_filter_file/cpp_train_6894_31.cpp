#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, m, n;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    if (n * 2 == m)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
