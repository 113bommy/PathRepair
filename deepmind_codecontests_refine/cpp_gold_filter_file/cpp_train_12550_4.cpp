#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long c, x, y, z = 1;
  cin >> n >> c >> y;
  for (int i = 1; i < n; i++) {
    cin >> x;
    if (x - y <= c)
      z++;
    else
      z = 1;
    y = x;
  }
  cout << z;
}
