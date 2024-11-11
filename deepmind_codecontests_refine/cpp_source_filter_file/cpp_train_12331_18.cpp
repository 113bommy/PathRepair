#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int c = 0;
  int m = 0;
  int a1, a2, a3, b1, b2, b3;
  int sumall = 0;
  ;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;
  c = a1 + a2 + a3;
  m = b1 + b2 + b3;
  if (c % 5 == 0)
    sumall += c / 5;
  else
    sumall += c / 5 + 1;
  if (m % 10 == 0)
    sumall += c / 10;
  else
    sumall += c / 10 + 1;
  if (sumall > n)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
