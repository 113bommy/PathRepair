#include <bits/stdc++.h>
using namespace std;
int main() {
  long double price, ua, kg, res;
  long double min = 200.0;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> ua >> kg;
    price = ua / kg;
    cerr << price;
    res = price * m;
    if (res < min) min = res;
  }
  cout << setprecision(8) << fixed << min;
}
