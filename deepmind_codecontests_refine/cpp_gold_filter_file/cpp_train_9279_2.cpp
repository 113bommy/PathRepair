#include <bits/stdc++.h>
using namespace std;
long long int n, x, y;
int main() {
  cin >> n >> x >> y;
  if (y < n || (y + 1 - n) * (y + 1 - n) + n - 1 < x)
    cout << -1;
  else {
    cout << y + 1 - n << "\n";
    for (int i = 1; i < n; i++) cout << 1 << "\n";
  }
  return 0;
}
