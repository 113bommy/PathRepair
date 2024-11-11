#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, m;
    cin >> n >> m;
    if (n % m == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
