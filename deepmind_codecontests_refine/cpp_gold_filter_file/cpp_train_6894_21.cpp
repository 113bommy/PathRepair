#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (n % m == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
