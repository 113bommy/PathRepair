#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int d[2048][2] = {0};
  d[0][1] = 1;
  for (int i = 0; n--; i ^= 1) {
    int x;
    cin >> x;
    for (int j = 0; j <= 1 << k; ++j) d[j][i] = 0;
    for (int j = 0; j <= 1 << k; ++j) {
      if (x != 4) (d[min(j + 2, 1 << k)][i] += d[j][i ^ 1]) %= 1000000007;
      if (x != 2)
        (d[(j & 2) ? 4 : min(j + 4, 1 << k)][i] += d[j][i ^ 1]) %= 1000000007;
    }
    if (!n) cout << d[1 << k][i] << '\n';
  }
  return 0;
}
