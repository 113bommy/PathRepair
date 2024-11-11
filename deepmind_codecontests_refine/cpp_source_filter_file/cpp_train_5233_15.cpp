#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0, m = 0;
    cin >> n >> m;
    (m < 2 * n) ? cout << "-1 -1\n" : cout << "1 " << (2 * n) << "\n";
  }
}
