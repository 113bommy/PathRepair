#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int n, m;
  while (t--) {
    cin >> n >> m;
    if (n == 1 || m == 1 || (n == m && n == 2))
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
    }
  }
}
