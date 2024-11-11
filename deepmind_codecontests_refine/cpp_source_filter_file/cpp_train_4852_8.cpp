#include <bits/stdc++.h>
using namespace std;
int gcd(int xx, int yy) {
  while (yy != 0) {
    xx = xx % yy;
    swap(xx, yy);
  }
  return xx;
}
int lcm(int xx, int yy) { return (xx / gcd(xx, yy)) * yy; }
int n, a, k;
double res;
int main() {
  cin >> n >> a;
  if (n == 3) {
    cout << "2 1 3" << endl;
    return 0;
  }
  res = double(n * a * 1.0 / 180.0);
  res = min(2 + int(round(res)), n);
  if (res == 0) {
    res += 1;
  }
  cout << 2 << " " << 1 << " " << res << endl;
}
