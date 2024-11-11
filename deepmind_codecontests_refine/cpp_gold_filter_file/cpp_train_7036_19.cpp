#include <bits/stdc++.h>
using namespace std;
set<int> s1, s2;
int main() {
  cin.sync_with_stdio(false);
  int T;
  int num;
  long long sum1, sum2;
  while (cin >> T) {
    while (T--) {
      sum1 = 0;
      sum2 = 0;
      for (int i = 0; i < 250; i++) {
        cin >> num;
        sum1 += num;
        sum2 += num * num;
      }
      if (250 * sum2 < sum1 * sum1 * 1.2) {
        cout << "poisson" << endl;
      } else {
        cout << "uniform" << endl;
      }
    }
  }
  return 0;
}
