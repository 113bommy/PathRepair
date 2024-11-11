#include <bits/stdc++.h>
using namespace std;
int main() {
  double m[5], w[5], hs, hu, x[5] = {500, 1000, 1500, 2000, 2500};
  double sum = 0;
  double q0 = 0, q1 = 0;
  double sum2 = 0;
  for (int i = 0; i < 5; i++) {
    cin >> m[i];
  }
  for (int i = 0; i < 5; i++) {
    cin >> w[i];
  }
  cin >> hs >> hu;
  for (int i = 0; i < 5; i++) {
    q0 = (3 / 10) * x[i];
    q1 = ((1 - m[i] / 250) * (x[i])) - (50 * w[i]);
    sum = max(q0, q1);
    sum2 += sum;
  }
  sum2 += (hs * 100);
  sum2 -= (hu * 50);
  cout << sum2;
  return 0;
}
