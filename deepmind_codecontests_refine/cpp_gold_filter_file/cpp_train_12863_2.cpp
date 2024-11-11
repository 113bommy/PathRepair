#include <bits/stdc++.h>
using namespace std;
int main() {
  int price, change, x, i = 1;
  cin >> price >> change;
  x = price;
  while (x % 10 != change && x % 10 != 0) {
    x += price;
    i++;
  }
  cout << i << endl;
  return 0;
}
