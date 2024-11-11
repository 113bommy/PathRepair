#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  if (n <= 9)
    cout << n;
  else if (n > 9 && n <= 99)
    cout << 9 + (n - 9) * 2;
  else if (n > 99 && n <= 999)
    cout << 189 + (n - 99) * 3;
  else if (n > 999 && n <= 9999)
    cout << 2889 + (n - 999) * 4;
  else if (n > 9999 && n <= 99999)
    cout << 38889 + (n - 9999) * 5;
  else if (n > 99999 && n <= 999999)
    cout << 488889 + (n - 99999) * 6;
  else if (n > 999999 && n <= 9999999)
    cout << 5888889 + (n - 999999) * 7;
  else if (n > 9999999 && n <= 99999999)
    cout << 68888889 + (n - 9999999) * 8;
  else if (n > 99999999 && n <= 999999999)
    cout << 788888889 + (n - 99999999) * 9;
  else
    cout << 8888888899;
  return 0;
}
