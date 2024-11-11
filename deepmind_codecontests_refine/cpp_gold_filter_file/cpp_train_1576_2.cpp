#include <bits/stdc++.h>
using namespace std;
int main() {
  float pi = 3.14159265358979323846;
  int n, r;
  cin >> n >> r;
  cout << fixed << setprecision(10)
       << r * (sin((2 * pi) / n)) /
              ((2 * (sin((n - 2) * pi / (2 * n))) - sin((2 * pi) / n)));
}
