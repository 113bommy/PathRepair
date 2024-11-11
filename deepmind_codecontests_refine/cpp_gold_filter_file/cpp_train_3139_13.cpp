#include <bits/stdc++.h>
const int A = 26;
using namespace std;
int main() {
  long long H, n;
  cin >> H >> n;
  vector<int> d(n);
  long long dam_full = 0, dam_max = 0, dam;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    dam_full += d[i];
    dam_max = min(dam_max, dam_full);
  }
  if (dam_full >= 0 && H + dam_max > 0)
    cout << -1;
  else {
    long long fullr = 0;
    if (H + dam_max <= 0)
      fullr = 0;
    else {
      fullr = (H + dam_max) / abs(dam_full);
      if ((H + dam_max) % abs(dam_full) != 0) fullr++;
      H += fullr * dam_full;
    }
    long long m = fullr * n, i = 0;
    while (H > 0) {
      m++;
      H += d[i];
      i++;
    }
    cout << m;
  }
}
