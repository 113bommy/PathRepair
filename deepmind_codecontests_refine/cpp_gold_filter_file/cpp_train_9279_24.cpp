#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, s, i;
  cin >> n >> x >> y;
  if (n > y) {
    cout << "-1" << endl;
    return 0;
  }
  s = (y - n + 1) * (y - n + 1) + n - 1;
  if (s < x)
    cout << "-1" << endl;
  else {
    cout << y - n + 1 << ' ';
    for (i = 1; i <= n - 1; i++) cout << 1 << ' ';
    cout << endl;
  }
}
