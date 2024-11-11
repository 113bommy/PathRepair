#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);
long long calc(long long p, long long t) {
  return max(3 * p / 10, p - p / 250 * t);
}
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (calc(a, b) > calc(c, d)) {
    cout << "Misha" << endl;
  } else if (calc(a, b) == calc(c, d)) {
    cout << "Tie" << endl;
  } else
    cout << "Vasya" << endl;
  return 0;
}
