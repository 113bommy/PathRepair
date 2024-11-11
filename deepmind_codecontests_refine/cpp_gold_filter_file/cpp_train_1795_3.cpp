#include <bits/stdc++.h>
using namespace std;
double f(double t) { return sqrt(fabs(t)) + 5 * pow(t, 3); }
int main() {
  int n;
  vector<int> v;
  while (cin >> n) {
    v.push_back(n);
  }
  reverse(v.begin(), v.end());
  for (auto i : v) {
    int x = i;
    double y = f((double)x);
    cout << "f(" << x << ") = ";
    if (y > 400)
      cout << "MAGNA NIMIS!";
    else
      cout << fixed << setprecision(2) << y;
    cout << "\n";
  }
}
