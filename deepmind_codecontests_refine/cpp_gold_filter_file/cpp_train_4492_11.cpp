#include <bits/stdc++.h>
using namespace std;
int n;
long long x, y;
int main() {
  cin >> n >> x >> y;
  if ((y - n + 1) > 0 && (y - n + 1) * (y - n + 1) + n - 1 >= x) {
    cout << y - n + 1;
    for (int i = 1; i < n; ++i) printf(" 1");
    cout << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
