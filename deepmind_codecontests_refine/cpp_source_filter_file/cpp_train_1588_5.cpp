#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  int tc;
  cin >> tc;
  while (tc--) {
    double n;
    cin >> n;
    n *= 2;
    double angle = 180 / n;
    angle *= ((double)3.14159265358979323846 / 180.0);
    double half = 0.5 / tan(angle);
    cout << half * 2;
  }
  return 0;
}
