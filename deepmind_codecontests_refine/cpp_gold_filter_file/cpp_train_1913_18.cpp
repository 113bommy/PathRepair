#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, c;
  cin >> n >> x >> y >> c;
  long long cnt = 1;
  int t = 1;
  n++;
  while (c > cnt) {
    t++;
    cnt += 4 * (t - 1);
    if (x < t) cnt -= 2 * (t - x) - 1;
    if (y < t) cnt -= 2 * (t - y) - 1;
    if (n - x < t) cnt -= 2 * (t - (n - x)) - 1;
    if (n - y < t) cnt -= 2 * (t - (n - y)) - 1;
    if (x + y < t) cnt += t - (x + y);
    if (x + (n - y) < t) cnt += t - (x + n - y);
    if (n - x + y < t) cnt += t - (n - x + y);
    if (n - x + (n - y) < t) cnt += t - (n - x + n - y);
  }
  cout << (t - 1) << endl;
  return 0;
}
