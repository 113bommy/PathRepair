#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x < y ? x : y;
}
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
const int N = 500010;
int main() {
  int n, mx = 0;
  read(n);
  static int cnt[N], tmx[N][2];
  for (int i = 1, x; i <= n; i++) read(x), cnt[x]++, chkmax(mx, x);
  for (int i = 1; i <= mx; i++) {
    if (cnt[i] >= 2) tmx[i][0] = tmx[i][1] = i;
    if (cnt[i] == 1) tmx[i][0] = i, tmx[i][1] = tmx[i - 1][0];
    if (!cnt[i]) tmx[i][0] = tmx[i - 1][0], tmx[i][1] = tmx[i - 1][1];
    cnt[i] += cnt[i - 1];
  }
  long long ans = 0;
  for (int y = 9; y <= mx; y++) {
    int mxx[2] = {-1, -1};
    long long cnty = 0;
    for (int k = 1; k <= mx / y; k++)
      cnty += 1ll * k * (cnt[min((k + 1) * y - 1, mx)] - cnt[k * y - 1]);
    for (int k = mx / y; ~k; k--) {
      int tmp = tmx[min((k + 1) * y - 1, mx)][0] - k * y;
      if (mxx[0] < tmp)
        mxx[1] = mxx[0], mxx[0] = tmp;
      else if (mxx[1] < tmp)
        mxx[1] = tmp;
      chkmax(mxx[1], tmx[min((k + 1) * y - 1, mx)][1] - k * y);
      int x = min(cnty - k, (1ll * k * y + mxx[0]) / 2);
      if (x > 1) chkmax(ans, 1ll * x * y);
      if (~mxx[1]) {
        x = min(cnty - 2 * k, 1ll * k * y + mxx[1]);
        if (x > 1) chkmax(ans, 1ll * x * y);
      }
      if (n - cnt[max(0, k * y + mxx[0] - 1)] > 1) {
        x = min(cnty - 2 * k - 1, 1ll * k * y + mxx[0]);
        if (x > 1) chkmax(ans, 1ll * x * y);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
