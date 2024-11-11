#include <bits/stdc++.h>
using namespace std;
long long t, tt, n, i;
int main() {
  cin >> t;
  for (tt = 1; tt <= t; tt++) {
    cin >> n;
    for (i = 4 * n; i >= 3 * n + 1; i--) cout << i << " ";
    cout << endl;
  }
}
