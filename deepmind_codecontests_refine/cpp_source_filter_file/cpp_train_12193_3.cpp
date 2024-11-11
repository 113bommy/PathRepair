#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[300005], y[300005];
int dx[300005], dy[300005];
const int BAD = 1012012012;
int trazi_x(int p, int x, int y) {
  if (x == y) return 1;
  if (k == 1) {
    if (p == 0)
      return x == y + 1 ? 1 : BAD;
    else
      return BAD;
  }
  if (x < y) {
    if (y > k * 1ll * x) return BAD;
    return 1;
  } else {
    if (p + x <= y * 1ll * k) {
      return 1;
    } else if (p + x > (y + 1ll) * k) {
      return BAD;
    } else {
      return p + x - y * 1ll * k;
    }
  }
}
int trazi_cross(int p, int x, int y) {
  if (k == 1) {
    if (p == 0)
      return x == y || x + 1 == y ? 1 : BAD;
    else
      return x + 1 == y ? 1 : BAD;
  }
  if (x == y) {
    if (p == k && x == 1) return BAD;
    return 1;
  }
  if (x > y) {
    if (x <= k * 1ll * y) return 1;
    return BAD;
  } else {
    if (y <= x * 1ll * k) return 1;
    if (y > (x + 1ll) * k) return BAD;
    return y - x * 1ll * k;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> y[i];
  dx[0] = dy[0] = 0;
  for (int i = 1; i <= n; i++) {
    dx[i] = dy[i] = BAD;
    if (dx[i - 1] != BAD) {
      dx[i] = min(dx[i], trazi_x(dx[i - 1], x[i], y[i]));
      dy[i] = min(dy[i], trazi_cross(dx[i - 1], x[i], y[i]));
    }
    if (dy[i - 1] != BAD) {
      dy[i] = min(dy[i], trazi_x(dy[i - 1], y[i], x[i]));
      dx[i] = min(dx[i], trazi_cross(dy[i - 1], y[i], x[i]));
    }
  }
  if (dx[n] != BAD || dy[n] != BAD)
    cout << "YES\n";
  else
    cout << "NO\n";
}
