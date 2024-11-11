#include <bits/stdc++.h>
using namespace std;
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double fg = (b * b - 4 * a * c);
  double mn = (-b - sqrt(fg)) / (2 * a);
  double mx = (sqrt(fg) - b) / (2 * a);
  if (mn < mx) swap(mn, mx);
  printf("%0.10lf %0.10lf \n", mn, mx);
}
