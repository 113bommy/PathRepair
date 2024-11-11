#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, k;
  cin >> x >> y >> k;
  cout << (x + y) / k << " ";
  if ((x % k + y % k) >= k) {
    cout << min(k - x % k, k - y % k);
  } else {
    cout << 0;
  }
  return 0;
}
