#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int sum, a;
  int minmove[t];
  for (int i = 0; i < t; i++) {
    cin >> sum;
    if (sum == 1) {
      minmove[i] = 0;
      continue;
    }
    a = sqrt(sum);
    if (a * a == sum)
      minmove[i] = 2 * (a - 1);
    else
      minmove[i] = 2 * sqrt(sum) - 1;
  }
  for (int i = 0; i < t; i++) {
    cout << minmove[i] << endl;
  }
  return 0;
}
