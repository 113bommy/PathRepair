#include <bits/stdc++.h>
using namespace std;
int a = 0, b = 0, c = 0, t = 0;
long long ans[83];
bool check(int k, int sum) {
  long long a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0;
  a = k / 100000000;
  if (a != 0) k = k - a * 100000000;
  b = k / 10000000;
  if (b != 0) k = k - b * 10000000;
  c = k / 1000000;
  if (c != 0) k = k - c * 1000000;
  d = k / 100000;
  if (d != 0) k = k - d * 100000;
  e = k / 10000;
  if (e != 0) k = k - e * 10000;
  f = k / 1000;
  if (f != 0) k = k - f * 1000;
  g = k / 100;
  if (g != 0) k = k - g * 100;
  h = k / 10;
  if (h != 0) k = k - h * 10;
  i = k;
  if (sum == a + b + c + d + e + f + g + h + i)
    return true;
  else
    return false;
}
int main() {
  cin >> a >> b >> c;
  long long x = 0, l = 1;
  for (int sum = 1; sum <= 81; sum++) {
    l = 1;
    for (int j = 1; j <= a; ++j) l = l * sum;
    x = b * l + c;
    if (check(x, sum) && x < 1000000000) {
      t++;
      ans[t] = x;
    }
  }
  cout << t << endl;
  for (int i = 1; i <= t; i++) cout << ans[i] << " ";
  return 0;
}
