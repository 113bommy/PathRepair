#include <bits/stdc++.h>
using namespace std;
const unsigned long long MOD = 257;
int ans[100005], sg[100005], mex[100005];
void getsg(int n) {
  for (int i = 2; i * (i + 1) / 2 <= n; i++) {
    if ((2 * n) % i == 0) {
      int t = 2 * n / i - i + 1;
      if ((t & 1) || t < 0) continue;
      t /= 2;
      mex[sg[t - 1 + i] ^ sg[t - 1]] = n;
      if (sg[t - 1 + i] ^ sg[t - 1] == 0)
        if (ans[n] == -1) ans[n] = i;
    }
  }
  sg[n] = -1;
  for (int i = 0;; i++) {
    if (mex[i] != n) {
      sg[n] = i;
      break;
    }
  }
  sg[n] ^= sg[n - 1];
  return;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  memset(ans, -1, sizeof(ans));
  for (int i = 3; i <= n; i++) {
    getsg(i);
  }
  cout << ans[n] << endl;
}
