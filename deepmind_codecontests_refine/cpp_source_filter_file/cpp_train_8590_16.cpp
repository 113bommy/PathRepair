#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, d, h;
  cin >> n >> d >> h;
  if (h * 2 < d || (d == 1 && h == 1 && n > 2)) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0; i < h; ++i) {
    cout << i + 1 << ' ' << i + 2 << '\n';
  }
  if (d > h) {
    cout << "1 " << h + 2 << '\n';
  }
  for (int i = 0; i + 1 < d - h; ++i) {
    cout << h + i + 2 << ' ' << h + i + 3 << '\n';
  }
  for (int i = d + 1; i < n; ++i) {
    cout << d << ' ' << i + 1 << '\n';
  }
  return 0;
}
