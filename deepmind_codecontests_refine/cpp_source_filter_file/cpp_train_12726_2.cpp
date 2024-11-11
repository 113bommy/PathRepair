#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    if (n >= 4)
      cout << 2 * m << "\n";
    else
      cout << m << "\n";
  }
}
