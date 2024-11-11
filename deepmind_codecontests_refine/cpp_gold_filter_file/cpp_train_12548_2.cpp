#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << -1;
    return 0;
  }
  cout << 99 << endl << 55 << endl << 11115 << endl;
  for (int i = 4; i <= n; i++) {
    for (int j = 1; j <= 2 * i; j++) cout << 5;
    cout << endl;
  }
}
