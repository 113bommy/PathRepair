#include <bits/stdc++.h>
using namespace std;
map<string, string> m;
int main() {
  long long n, m = 1000000001, i, x, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    y = y + x;
    if (x % 2 == 1 && m > x) m = x;
  }
  if (y % 2 == 1) y = y - m;
  cout << y;
  return 0;
}
