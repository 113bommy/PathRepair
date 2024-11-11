#include <bits/stdc++.h>
using namespace std;
double h, l;
int main() {
  cin >> h >> l;
  double ans = (h * h + l * l) / (2 * h) - h;
  cout << fixed << setprecision(10) << endl;
}
