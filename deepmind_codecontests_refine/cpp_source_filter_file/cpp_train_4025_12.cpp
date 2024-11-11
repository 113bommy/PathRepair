#include <bits/stdc++.h>
using namespace std;
int func(int hh, int mm) {
  int dans = 0;
  while (hh < 20) {
    if (mm == 59) {
      mm = 0;
      hh++;
    } else {
      mm++;
    }
    dans++;
  }
  return dans;
}
int main() {
  ios_base::sync_with_stdio(0);
  int hh, mm;
  long long int H, D, C, N;
  cin >> hh >> mm;
  cin >> H >> D >> C >> N;
  cout << fixed << setprecision(10);
  if (hh >= 20) {
    long double newCost = 0.2 * C;
    long double total = ceil(H * 1.000 / N);
    cout << total * newCost << endl;
  } else {
    long double newCost = C;
    long double total = ceil(H * 1.000 / N);
    total = total * newCost;
    int wait = func(hh, mm);
    long double someCost = 0.2 * C;
    H += wait * D;
    long double total2 = ceil(H * 1.000 / N);
    total2 = total2 * someCost;
    cout << min(total, total2) << endl;
  }
  return 0;
}
