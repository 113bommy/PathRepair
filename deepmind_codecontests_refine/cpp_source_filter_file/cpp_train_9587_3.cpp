#include <bits/stdc++.h>
using namespace std;
int n, k;
int a, y;
int g;
int gcd(int x1, int y1) {
  if (y1 == 0) return x1;
  if (x1 < y1)
    return gcd(y1, x1);
  else
    return gcd(y1, x1 % y1);
}
int main() {
  int i, j, sum;
  cin >> n >> k;
  g = 0;
  for (i = 0; i < n; i++) {
    cin >> a;
    y = a % k;
    g = gcd(g, y);
  }
  if (g == 0) {
    cout << "1" << endl << "0";
    return 0;
  }
  sum = k / g;
  cout << sum << endl;
  if (k / g * g == k) {
    sum--;
    cout << "0 ";
  }
  for (i = 0; i < sum; i++) {
    cout << g * (i + 1) << " ";
  }
  return 0;
}
