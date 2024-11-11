#include <bits/stdc++.h>
using namespace std;
int main() {
  float a, b, c, d;
  float e;
  cin >> a >> b >> c >> d;
  e = a * d / (b * d - a * c);
  ios::fixed;
  cout << setprecision(12) << e;
}
