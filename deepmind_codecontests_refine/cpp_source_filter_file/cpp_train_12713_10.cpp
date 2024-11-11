#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int r, g, b, a = n * 2, d = n * 5, c = n * 8;
  r = a / k;
  if (a % k != 0) r++;
  b = d / k;
  if (d % k != 0) d++;
  g = c / k;
  if (c % k != 0) g++;
  int t = r + b + g;
  cout << t;
  return 0;
}
