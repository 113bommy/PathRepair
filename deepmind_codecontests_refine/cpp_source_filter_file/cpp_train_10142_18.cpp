#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0 << " " << a << " " << 0 << "\n";
    return 0;
  }
  if ((a + b) % 2 == 0) {
    int mid = (a + b) / 2;
    if (a < b)
      cout << mid - 1 << " " << 1 << " " << 6 - mid << "\n";
    else
      cout << 6 - mid << ' ' << 1 << " " << mid - 1 << "\n";
  } else {
    int mid = (a + b) / 2;
    if (a < b)
      cout << mid << " " << 0 << " " << 6 - mid << "\n";
    else
      cout << 6 - mid << " " << 0 << ' ' << mid << "\n";
  }
}
