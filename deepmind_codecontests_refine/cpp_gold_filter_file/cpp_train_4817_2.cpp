#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int sum = 0, n, maxx = 0, e;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> e;
      if (e > maxx) maxx = e;
      sum = sum + e;
    }
    if (maxx > sum / 2)
      cout << "T" << endl;
    else if (sum % 2 == 1)
      cout << "T" << endl;
    else
      cout << "HL" << endl;
  }
}
