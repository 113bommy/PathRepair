#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int val = n / 2;
    if ((2 + (n % 2) == 3))
      cout << "7";
    else
      cout << "1";
    int m = val - 1;
    for (int i = 0; i < m; i++) {
      cout << "1";
    }
    cout << endl;
  }
}
