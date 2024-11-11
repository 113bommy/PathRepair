#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int x, y;
  cin >> x >> y;
  int sum = abs(x) + abs(y);
  if (x <= 0 && y <= 0) {
    cout << 0 - sum << " " << 0 << " ";
    cout << 0 << " " << 0 - sum;
    return 0;
  }
  if (x <= 0 && y >= 0) {
    cout << 0 - sum << " " << 0 << " ";
    cout << 0 << " " << sum;
    return 0;
  }
  if (x >= 0 && y <= 0) {
    cout << 0 << " " << sum;
    cout << " " << 0 - sum << " " << 0;
    return 0;
  }
  if (x >= 0 && y >= 0) {
    cout << 0 << " " << sum;
    cout << " " << sum << " " << 0;
    return 0;
  }
  return 0;
}
