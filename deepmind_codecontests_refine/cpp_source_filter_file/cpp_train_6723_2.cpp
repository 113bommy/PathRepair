#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int a, b, x, y;
  cin >> a >> b;
  if (a < b) {
    cout << -1;
    return 0;
  }
  x = (a - b) / 2;
  y = x + b;
  if ((x ^ y) != b || (x + y) != a) {
    cout << -1;
    return 0;
  }
  cout << x << " " << y;
  return 0;
}
