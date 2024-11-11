#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 5;
int vec[MX][10];
int main() {
  for (int i = 1; i < MX; i++) {
    int now = i;
    while (now >= 10) {
      int x = 1;
      while (now) {
        if (now % 10 != 0) x *= (now % 10);
        now /= 10;
      }
      now = x;
    }
    vec[i][now]++;
    for (int k = 1; k < 10; k++) vec[i][k] += vec[i - 1][k];
  }
  int n;
  cin >> n;
  while (n--) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << vec[r][k] - vec[l - 1][k] << "\n";
  }
  return 0;
}
