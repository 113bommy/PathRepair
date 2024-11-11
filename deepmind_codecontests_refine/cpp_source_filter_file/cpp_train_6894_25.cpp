#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    if (n == 2 * m)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
