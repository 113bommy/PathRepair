#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  cout.precision(12);
  cout << fixed;
  int n, d, h;
  cin >> n >> d >> h;
  if (d < h || d > 2 * h) {
    cout << "NO\n";
    return 0;
  }
  if (d == 1 && n > 2) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i <= h; i++) {
    cout << i << " " << i + 1 << "\n";
  }
  int prev = 1, next = h + 2;
  for (int i = h + 1; i <= d; i++) {
    cout << prev << " " << next << "\n";
    prev = next++;
  }
  next = d + 2;
  d == h ? prev = 2 : prev = 1;
  for (int i = d + 1; i < n; i++) {
    cout << prev << " " << next++ << "\n";
  }
}
