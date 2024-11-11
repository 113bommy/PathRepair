#include <bits/stdc++.h>
using namespace std;
int main() {
  double wrong[5];
  double points[5] = {500, 1000, 1500, 2000, 2500};
  double minutes[5];
  double two_fifty = 250;
  double fifty = 50;
  double point_three = 0.3;
  double one = 1;
  for (int i = 0; i < 5; i++) cin >> minutes[i];
  for (int i = 0; i < 5; i++) cin >> wrong[i];
  double hs, hu;
  cin >> hs >> hu;
  hs *= 100;
  hu *= 50;
  double ans = hs - hu;
  for (int i = 0; i < 5; i++)
    ans +=
        max(point_three * points[i],
            ((one - minutes[i] / two_fifty) * points[i]) - (fifty * wrong[i]));
  cout << int(ans) << endl;
  return 0;
}
