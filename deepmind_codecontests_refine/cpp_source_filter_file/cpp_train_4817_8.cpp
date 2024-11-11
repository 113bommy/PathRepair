#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int sum, n, max = 0, e;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> e;
      if (e > max) max = e;
      sum = sum + e;
    }
    if (max > sum / 2)
      cout << "T" << endl;
    else if (sum % 2 == 1)
      cout << "T" << endl;
    else
      cout << "HL" << endl;
  }
}
