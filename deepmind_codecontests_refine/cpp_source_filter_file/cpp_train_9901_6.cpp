#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 6;
int bit_val[] = {-1, 1}, s[100][10], U = -1e9, D = 1e9, L = 1e9, R = -1e9, ans;
int n, mx1[100], mx2[100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < (1 << 6); i++) {
    mx1[i] = mx2[i] = -3e8;
    vector<int> bits;
    for (int j = 0; j < 6; j++) bits.push_back(bit_val[((1 << j) & i) != 0]);
    s[i][1] = bits[0] + bits[2];
    s[i][2] = bits[1] + bits[3];
    s[i][3] = bits[4] - bits[0];
    s[i][4] = bits[5] - bits[1];
    s[i][5] = -bits[2] - bits[4];
    s[i][6] = -bits[3] - bits[5];
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    D = min(D, y);
    U = max(U, y);
    L = min(L, x);
    R = max(R, x);
    for (int j = 0; j < (1 << 6); j++) {
      if (i >= 3) ans = max(ans, mx2[j] + s[j][5] * x + s[j][6] * y);
      if (i >= 2) mx2[j] = max(mx2[j], mx1[j] + s[j][3] * x + s[j][4] * y);
      mx1[j] = max(mx1[j], s[j][1] * x + s[j][2] * y);
    }
  }
  cout << ans;
  for (int i = 4; i <= n; i++) cout << " " << 2 * (U - D + R - L);
}
