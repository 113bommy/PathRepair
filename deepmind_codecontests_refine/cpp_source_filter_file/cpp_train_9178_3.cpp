#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, l;
  cin >> h >> l;
  double ans = 0;
  ans = (double(l * l) - double(h * h)) / double(2 * h);
  cout << fixed << setprecision(13) << ans << endl;
}
