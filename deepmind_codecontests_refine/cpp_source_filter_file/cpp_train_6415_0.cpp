#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x % 4 == 0) cout << ((x >= 4) ? (x / 4) : -1);
    if (x % 4 == 1) cout << ((x >= 9) ? (x / 4 - 1) : -1);
    if (x % 4 == 2) cout << ((x >= 6) ? (x / 4) : -1);
    if (x % 4 == 3) cout << ((x >= 15) ? (x / 4 - 2) : -1);
    cout << endl;
  }
}
