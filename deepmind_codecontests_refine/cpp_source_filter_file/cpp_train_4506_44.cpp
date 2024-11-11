#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (c > b) swap(c, b);
    cout << b;
  }
  return 0;
}
