#include <bits/stdc++.h>
using namespace std;
int x, z, sum = 0, out;
int main() {
  cin >> x >> z;
  sum += z;
  for (int i = 0; i < x; i++) {
    char po;
    int t;
    cin >> po >> t;
    if (po == '+') {
      sum += t;
      continue;
    }
    if (po == '-') {
      if (sum - t < 0) {
        out++;
      } else
        sum -= t;
    }
  }
  cout << sum << " " << out << endl;
  return 0;
}
