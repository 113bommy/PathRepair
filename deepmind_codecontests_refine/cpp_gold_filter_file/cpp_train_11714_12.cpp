#include <bits/stdc++.h>
using namespace std;
int main() {
  double d = 0, L = 0, v1 = 0, v2 = 0;
  double min = 0, max = 0;
  cin >> d >> L >> v1 >> v2;
  double t = 0;
  double i;
  t = (L - d) / (v1 + v2);
  cout << fixed << t;
  return 0;
}
