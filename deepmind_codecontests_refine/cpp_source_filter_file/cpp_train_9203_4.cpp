#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int guardpost1[4], guardpost2[4];
  int guardpostAll[4];
  int minIdx = 0;
  for (int i = 0; i < 4; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    guardpost1[i] = a < b ? a : b;
    guardpost2[i] = c < d ? c : d;
    guardpostAll[i] = guardpost1[i] + guardpost2[i];
  }
  for (int i = 0; i < 4; i++) {
    if (guardpostAll[i] <= n) {
      cout << i + 1 << " " << guardpost1[i] << " " << n - guardpost2[i] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
