#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  int num1 = n * y / 100;
  float num2 = n * y / 100.0;
  if (num2 > num1) num1++;
  if (num1 > x)
    cout << abs(num1 - x) << endl;
  else
    cout << 0 << endl;
  return 0;
}
