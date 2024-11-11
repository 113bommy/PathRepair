#include <bits/stdc++.h>
using namespace std;
const int W = int(1e5) * 2 + 10;
int a[W], n, d, h;
bool b[W];
int main() {
  cin >> n >> d >> h;
  if ((n <= d) || (d < h) || (d > 2 * h)) {
    cout << -1;
    return 0;
  }
  if ((h == d) && (h == 1) && (n > 2)) {
    cout << -1;
    return 0;
  }
  if ((h == d) && (n == 2)) {
    cout << "1 2";
    return 0;
  }
  if (h == d) {
    for (int i = 1; i <= h; i++) {
      cout << i << i + 1 << "\n";
    }
    for (int i = h + 1; i < n; i++) cout << 2 << " " << i + 1 << "\n";
    return 0;
  }
  for (int i = 1; i <= h; i++) cout << i << " " << i + 1 << "\n";
  for (int i = (h + 1); i <= d; i++)
    if (i == (h + 1))
      cout << 1 << " " << i + 1 << "\n";
    else
      cout << i << " " << i + 1 << "\n";
  for (int i = d + 2; i <= n; i++) cout << 1 << " " << i << "\n";
  return 0;
}
