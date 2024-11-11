#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t0, t1, x0, x1, t;
  cin >> t0 >> t1 >> x0 >> x1 >> t;
  long long int best0 = 0, best1 = 0;
  if (t == t0 && t == t1) {
    cout << x0 << " " << x1 << endl;
    return 0;
  }
  if (t == t0) {
    cout << x0 << " 0" << endl;
    return 0;
  }
  if (t == t1) {
    cout << "0 " << x1 << endl;
    return 0;
  }
  for (long long int cold = 0, hot = 0; cold <= x0; cold++) {
    while ((cold * t0 + hot * t1) < (cold + hot) * t) hot++;
    if (x0 < hot) break;
    if (best0 == 0 && best1 == 0) {
      best0 = cold;
      best1 = hot;
    }
    if ((cold * t0 + hot * t1) * (best0 + best1) <=
        (best0 * t0 + best1 * t1) * (cold + hot)) {
      best0 = cold;
      best1 = hot;
    }
  }
  if (best0 == 0) best1 = x1;
  cout << best0 << " " << best1 << endl;
}
