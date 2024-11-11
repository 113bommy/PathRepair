#include <bits/stdc++.h>
using namespace std;
int main() {
  long long d, l, v1, v2;
  cin >> d >> l >> v1 >> v2;
  l -= d;
  l *= 10000000;
  int sum = v1 + v2;
  double ans = (double)l / sum;
  ans /= 10000000;
  cout << fixed << setprecision(12) << ans;
}
