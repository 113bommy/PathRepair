#include <bits/stdc++.h>
using namespace std;
int main() {
  float a, b, c, d;
  float e;
  cin >> a >> b >> c >> d;
  e = a * d / (a * d + b * c - a * c);
  ios::fixed;
  cout << setprecision(12) << e;
}
