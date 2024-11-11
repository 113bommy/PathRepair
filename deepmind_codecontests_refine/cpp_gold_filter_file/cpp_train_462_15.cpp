#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
const double PI = M_PI;
const int OO = INT_MAX;
template <class A, class B>
A convert(B x) {
  stringstream s;
  s << x;
  A r;
  s >> r;
  return r;
}
int main() {
  double arr[6];
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }
  double distance = sqrt((arr[1] - arr[3]) * (arr[1] - arr[3]) +
                         (arr[2] - arr[4]) * (arr[2] - arr[4]));
  cout << ceil(distance / (2.0 * arr[0])) << '\n';
  return 0;
}
