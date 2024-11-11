#include <bits/stdc++.h>
using namespace std;
void solve() {
  float h, c, t;
  cin >> h >> c >> t;
  if (t >= h) {
    cout << "1\n";
    return;
  } else if (2 * t <= (h + c)) {
    cout << "2\n";
    return;
  } else {
    int val = (h - t) / (2 * t - h - c);
    float t1 = ((val + 1) * h + val * c) / (2 * val + 1);
    val++;
    float t2 = ((val + 1) * h + val * c) / (2 * val + 1);
    if (abs(t - t1) <= abs(t - t2)) {
      val--;
    }
    cout << 2 * val + 1 << "\n";
  }
}
int main() {
  int t;
  t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
