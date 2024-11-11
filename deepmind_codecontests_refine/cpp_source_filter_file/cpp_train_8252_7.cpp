#include <bits/stdc++.h>
using namespace std;
int t, n, k, i;
int main() {
  cin >> t;
  for (k = 1; k <= t; k++) {
    cin >> n;
    cout << n << endl;
    for (i = n; i >= 1; i--) cout << i << ' ';
    cout << endl;
  }
  return 0;
}
