#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int main() {
  double a, b;
  cin >> a >> b;
  double sump = a + b, summ = a - b;
  double k = sump / (2 * b);
  double k2 = summ / (2 * b);
  if (b > a) {
    cout << "-1";
    return 0;
  }
  if (a == b) {
    printf("%.9lf", b);
    return 0;
  }
  double ans = min((a + b) / (2 * floor(k)), (a - b) / (2 * floor(k2)));
  printf("%.9lf", ans);
  return 0;
  return 0;
}
