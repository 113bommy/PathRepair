#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, h;
  cin >> n;
  cin >> h;
  for (int i = 0; i < n - 1; i++) {
    double tmp;
    tmp = sqrt(h * (i + 1) * h / n);
    cout << setprecision(11) << tmp << endl;
  }
  return 0;
}
