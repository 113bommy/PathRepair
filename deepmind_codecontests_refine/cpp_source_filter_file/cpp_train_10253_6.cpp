#include <bits/stdc++.h>
using namespace std;
int v1, v2;
int t, d;
void solve() {
  int res = 0;
  int vc = v1;
  for (int i = 0; i < t; ++i) {
    res += vc;
    for (int j = d; j >= -1 * d; --j) {
      if (abs(vc + j - v2) <= (t - i - 1) * d) {
        vc += j;
        break;
      }
    }
  }
  cout << res << endl;
}
void read() {
  cin >> v1 >> v2;
  cin >> t >> d;
}
int main() {
  read();
  solve();
  return 0;
}
