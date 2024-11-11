#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, c = 0;
  cin >> n >> x >> y;
  if (y <= n) {
    cout << -1 << endl;
    return 0;
  }
  if ((n - 1) + ((y - n + 1) * (y - n + 1)) < x) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i < n; i++) cout << 1 << endl;
  cout << y - n + 1 << endl;
  return 0;
}
