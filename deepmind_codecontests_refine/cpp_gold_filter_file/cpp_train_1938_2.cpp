#include <bits/stdc++.h>
using namespace std;
long double co(long double x, long double y) { return x / sqrt(x * x + y * y); }
long double si(long double x, long double y) { return y / sqrt(x * x + y * y); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long double r, d;
  cin >> r >> d;
  long long n;
  cin >> n;
  long long cnt = 0;
  while (n--) {
    long double x, y, xy;
    cin >> x >> y >> xy;
    if (xy <= d) {
      long double dist = sqrt(x * x + y * y);
      if (dist + xy <= r && dist - xy >= (r - d)) cnt++;
    }
  }
  cout << cnt;
}
