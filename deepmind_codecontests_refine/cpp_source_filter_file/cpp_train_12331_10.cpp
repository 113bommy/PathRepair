#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, a2, a3, b1, b2, b3, sum1 = 0, sum2 = 0, n;
  int avg1, avg2;
  cin >> a1 >> a2 >> a3;
  cin >> b1 >> b2 >> b3;
  cin >> n;
  sum1 = a2 + a2 + a3;
  sum2 = b1 + b2 + b3;
  avg1 = sum1 / 5;
  avg2 = sum2 / 10;
  if (sum1 % 5 > 0) avg1++;
  if (sum2 % 10 > 0) avg2++;
  if (avg1 + avg2 <= n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
