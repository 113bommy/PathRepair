#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, x, y;
  cin >> n >> x >> y;
  long long z = n, cnt = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
  while (z--) {
    long long a, b;
    cin >> a >> b;
    if (a <= x) {
      cnt++;
    }
    if (a >= x) {
      cnt2++;
    }
    if (b <= y) {
      cnt3++;
    }
    if (b >= y) {
      cnt4++;
    }
  }
  cout << max(cnt, max(cnt2, max(cnt3, cnt4))) << '\n';
  if (max(cnt, max(cnt2, max(cnt3, cnt4))) == cnt) {
    cout << x - 1 << " " << y << '\n';
    return;
  }
  if (max(cnt, max(cnt2, max(cnt3, cnt4))) == cnt2) {
    cout << x + 1 << " " << y << '\n';
    return;
  }
  if (max(cnt, max(cnt2, max(cnt3, cnt4))) == cnt3) {
    cout << x << " " << y - 1 << '\n';
    return;
  }
  if (max(cnt, max(cnt2, max(cnt3, cnt4))) == cnt4) {
    cout << x << " " << y + 1 << '\n';
    return;
  }
}
int main() {
  long long t = 1;
  while (t--) {
    solve();
  }
}
