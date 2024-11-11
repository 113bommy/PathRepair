#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int C = 0; C < t; C++) {
    long long int n, x, m;
    cin >> n >> x >> m;
    vector<long long int> interval = {x, x};
    long long int output = 1;
    for (int iter = 0; iter < m; iter++) {
      long long int l, r;
      cin >> l >> r;
      if (((l < interval[0]) && (r < interval[0])) ||
          ((l > interval[1]) && (r > interval[1]))) {
        continue;
      }
      if (l < interval[0]) interval[0] = l;
      if (r > interval[1]) interval[1] = r;
    }
    output = (interval[0] - interval[1]);
    if (output < 0) output *= -1;
    cout << output + 1 << endl;
  }
  return 0;
}
