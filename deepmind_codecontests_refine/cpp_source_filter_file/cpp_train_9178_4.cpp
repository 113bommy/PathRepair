#include <bits/stdc++.h>
using namespace std;
int h, l;
int main() {
  cin >> h >> l;
  cout.precision(18);
  cout << abs(h * h - l * l) / (2.0 * h);
  return 0;
}
