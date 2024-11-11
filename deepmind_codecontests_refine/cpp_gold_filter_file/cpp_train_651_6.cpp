#include <bits/stdc++.h>
using namespace std;
long long t, tt, n, i;
int main() {
  cin >> t;
  for (tt = 1; tt <= t; tt++) {
    cin >> n;
    for (i = 4 * n; i >= 2 * n + 2; i = i - 2) cout << i << " ";
    cout << endl;
  }
}
