#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n < 10)
    cout << n;
  else if (n < 100)
    cout << 9 + (n - 9) * 2;
  else if (n < 1000)
    cout << 189 + (n - 99) * 3;
  else if (n < 10000)
    cout << 2889 + (n - 999) * 4;
  else if (n < 100000)
    cout << 38889 + (n - 9999) * 5;
  else if (n < 1000000)
    cout << 488889 + (n - 99999) * 6;
  else if (n < 10000000)
    cout << 5888889 + (n - 999999) * 7;
  else if (n < 100000000)
    cout << 68888889 + (n - 9999999) * 8;
  else if (n < 1000000000)
    cout << 788888889 + (n - 99999999) * 9;
  else if (n == 1000000000)
    cout << 8888888899;
}
