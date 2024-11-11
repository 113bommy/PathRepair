#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n == 1) {
    if (k)
      cout << -1 << endl;
    else
      cout << 1 << endl;
    return 0;
  }
  int x = k - ((n - 2) / 2);
  if (x <= 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << x;
  x *= 2;
  cout << " " << x;
  for (int i = 2; i < n; i++) {
    x++;
    cout << " " << x;
  }
  cout << endl;
  return 0;
}
