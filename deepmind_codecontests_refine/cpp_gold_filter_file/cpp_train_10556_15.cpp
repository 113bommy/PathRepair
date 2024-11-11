#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long x = 0, y = 0;
  cin >> x >> y;
  vector<long long> p1, p2;
  p1.reserve(2);
  p2.reserve(2);
  if (x > 0) {
    p1[0] = x + abs(y);
    p2[0] = 0;
  } else {
    p1[0] = -(abs(x) + abs(y));
    p2[0] = 0;
  }
  if (y > 0) {
    p1[1] = 0;
    p2[1] = abs(y) + abs(x);
  } else {
    p1[1] = 0;
    p2[1] = -(abs(y) + abs(x));
  }
  if (p1[0] > p2[0]) {
    cout << p2[0] << " " << p2[1] << " " << p1[0] << " " << p1[1];
  } else {
    swap(p1, p2);
    cout << p2[0] << " " << p2[1] << " " << p1[0] << " " << p1[1];
  }
  return 0;
}
