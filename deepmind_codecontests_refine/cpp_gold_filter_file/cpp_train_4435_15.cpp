#include <bits/stdc++.h>
using namespace std;
int main() {
  float f, i, n, h;
  cin >> n >> h;
  for (i = 1; i < n; i++) {
    f = (sqrt(i / n)) * h;
    cout << fixed << setprecision(6) << f << " ";
  }
  return 0;
}
