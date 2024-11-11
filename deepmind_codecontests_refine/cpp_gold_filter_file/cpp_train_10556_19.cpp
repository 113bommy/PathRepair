#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int long long x, y;
  cin >> x >> y;
  int long long sum = abs(x) + abs(y);
  if (x > 0 && y > 0) {
    cout << "0 " << abs(sum) << " " << abs(sum) << " 0";
  } else if (x < 0 && y > 0) {
    cout << -1 * abs(sum) << " 0"
         << " 0 " << abs(sum);
  } else if (x < 0 && y < 0) {
    cout << -1 * abs(sum) << " 0"
         << " 0 " << -1 * abs(sum);
  } else {
    cout << "0 " << -1 * abs(sum) << " " << abs(sum) << " 0";
  }
  return 0;
}
