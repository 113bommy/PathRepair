#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> c >> b >> d;
  int p = (3 * a) / 10;
  int q = (3 * c) / 10;
  int m = a - (a * b) / 250;
  int n = c - (c * d) / 250;
  int result1;
  int result2;
  if (p >= m)
    result1 = p;
  else
    result1 = m;
  if (q >= n)
    result2 = q;
  else
    result2 = n;
  if (result1 > result2) cout << "Misha" << endl;
  if (result1 < result2) cout << "Vasya" << endl;
  if (result1 == result2) cout << "Tie" << endl;
  return 0;
}
