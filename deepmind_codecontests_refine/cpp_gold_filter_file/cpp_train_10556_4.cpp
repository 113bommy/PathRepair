#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y;
  cin >> x >> y;
  long long sum = abs(x) + abs(y);
  if (x > 0 && y > 0)
    cout << 0 << " " << sum << " " << sum << " " << 0;
  else if (x < 0 && y > 0)
    cout << -sum << " " << 0 << " " << 0 << " " << sum;
  else if (x > 0 && y < 0)
    cout << 0 << " " << -sum << " " << sum << " " << 0;
  else if (x < 0 && y < 0)
    cout << -sum << " " << 0 << " " << 0 << " " << -sum;
  return 0;
}
