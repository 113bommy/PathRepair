#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, g;
  cin >> n >> g;
  g %= 4 * n;
  long long xx, yy;
  cin >> xx >> yy;
  long long x[n], y[n];
  for (int(i) = int(0); i < int(n); ++i) cin >> x[i] >> y[i];
  for (int(i) = int(1); i < int(g + 1); ++i) {
    long long dx = xx - x[(i - 1) % n];
    long long dy = yy - y[(i - 1) % n];
    xx -= 2 * dx;
    yy -= 2 * dy;
  }
  cout << xx << " " << yy << endl;
}
