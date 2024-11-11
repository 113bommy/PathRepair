#include <bits/stdc++.h>
using namespace std;
int main() {
  long int t, cont = 0, i, j;
  long int L, v, l, r, k;
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> L >> v >> l >> r;
    cout << L / v - (r / v - (l - 1) / v) << endl;
  }
  return 0;
}
