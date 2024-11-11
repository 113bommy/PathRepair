#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e, f = 0, h = 0, k = 0, sum = 0, sum1 = 0;
  cin >> a >> b >> c >> d >> e;
  sum = b * a + d * 2;
  sum1 = c * a + e * 2;
  if (sum == sum1) {
    cout << "Friendship" << endl;
  } else if (sum < sum1) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }
  return 0;
}
