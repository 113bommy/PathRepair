#include <bits/stdc++.h>
using namespace std;
const long long N = 1e17;
const long long sz = 2e5 + 5;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long r, c, rb, cb, rd, cd, mv1 = 1, mv2 = 1;
    cin >> r >> c >> rb >> cb >> rd >> cd;
    long long time = 0;
    while (true) {
      if (cb == cd || rb == rd) {
        break;
      } else {
        if (rb + mv1 > r || rb + mv1 <= 0) {
          mv1 *= -1;
        } else if (cb + mv2 > c || cb + mv2 <= 0) {
          mv2 *= -1;
        }
        rb += mv1;
        cb += mv2;
      }
      time++;
    }
    cout << time << endl;
  }
}
