#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int k = 0; k < t; k++) {
    int n, m;
    cin >> n >> m;
    if (n % m == 0)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
