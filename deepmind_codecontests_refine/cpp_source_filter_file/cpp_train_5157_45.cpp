#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000005;
const int mod = 1e9 + 7;
const int inf = 1e9 + 5;
int used[maxn];
int getvuelta(int dir, int px, int py, int x, int y) {
  int donde = 0;
  if (px == x) {
    if (y > py)
      donde = 0;
    else
      donde = 1;
  } else {
    if (x > px)
      donde = 2;
    else
      donde = 3;
  }
  if (dir == 0) {
    return donde;
  } else if (dir == 1) {
    if (donde == 2) return 3;
    return 2;
  } else if (dir == 2) {
    if (donde == 0) return 3;
    return 2;
  } else {
    if (donde == 0) return 2;
    return 3;
  }
}
void solve() {
  int n;
  cin >> n;
  int px, py;
  cin >> px >> py;
  cin >> px >> py;
  int dir = 0;
  int ans = 0;
  int vuelta = -1;
  for (int i = 1; i < n; i++) {
    int xx, yy;
    cin >> xx >> yy;
    int nueva = getvuelta(dir, px, py, xx, yy);
    if (vuelta == -1) {
      vuelta = nueva;
    } else if (vuelta != nueva) {
      ans++;
    }
    if (dir == 0) {
      dir = nueva;
    } else if (dir == 1) {
      if (nueva == 3)
        dir = 2;
      else
        dir = 3;
    } else if (dir == 2) {
      if (nueva == 3)
        dir = 0;
      else
        dir = 1;
    } else {
      if (nueva == 2)
        dir = 0;
      else
        dir = 1;
    }
    px = xx;
    py = yy;
  }
  cout << ans << '\n';
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
