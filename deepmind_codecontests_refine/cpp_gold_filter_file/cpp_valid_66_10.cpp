#include <bits/stdc++.h>
using namespace std;
int solve(int k) {
  int res;
  for (int i = 1; k > 0; i++) {
    if (i % 3 != 0 && i % 10 != 3) {
      res = i;
      k--;
    }
  }
  return res;
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int k;
    cin >> k;
    cout << solve(k) << endl;
  }
  return 0;
}
