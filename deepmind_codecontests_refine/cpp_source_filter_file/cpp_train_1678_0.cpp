#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int L, v, l, r;
    cin >> L >> v >> l >> r;
    int k = 0;
    if (v % 2 == 0) {
      k++;
    }
    cout << L / v - (r / v + 1 - l / v) + k << endl;
  }
}
