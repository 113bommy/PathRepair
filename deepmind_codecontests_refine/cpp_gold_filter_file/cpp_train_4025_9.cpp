#include <bits/stdc++.h>
using namespace std;
int main() {
  double H, D, C, N;
  double s1, s2;
  double cost1, cost2, cost;
  int hour, minute;
  int num;
  cin >> hour >> minute;
  cin >> H >> D >> C >> N;
  num = (19 - hour) * 60 + 60 - minute;
  if (num <= 0) {
    s1 = ceil(H / N);
    cost1 = s1 * (C * 0.8);
    cout << cost1 << endl;
    return 0;
  }
  s1 = ceil(H / N);
  cost1 = s1 * C;
  H = H + num * D;
  s2 = ceil(H / N);
  cost2 = s2 * C * 0.8;
  cost = min(cost1, cost2);
  printf("%.4lf\n", cost);
}
