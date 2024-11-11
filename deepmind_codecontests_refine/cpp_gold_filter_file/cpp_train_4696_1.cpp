#include <bits/stdc++.h>
using namespace std;
const int LIM = 1e5;
const int INF = 1e9;
const long long INF64 = 1e18;
const int MOD = INF + 7;
const double EPS = 1e-9;
long long gcd(long long a, long long b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long a, b, x_, y_;
  cin >> a >> b >> x_ >> y_;
  long long gs = gcd(x_, y_);
  x_ /= gs;
  y_ /= gs;
  cout << min(a / x_, b / y_);
  return 0;
}
