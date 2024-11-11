#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  float a[n];
  float p[n];
  float price = 1000;
  float tprice = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cin >> p[i];
    price = min(price, p[i]);
    tprice += price * a[i];
  }
  cout << tprice;
  return 0;
}
