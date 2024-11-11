#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  vector<int> v;
  int sq = sqrt(min(a, b));
  for (int i = 2; i <= sq; i++) {
    if (a % i == 0 && b % i == 0) {
      v.push_back(i);
    }
    int x = a / i, y = b / i;
    if (a % x == 0 && b % x == 0) v.push_back(x);
    if (a % y == 0 && b % y == 0) v.push_back(y);
  }
  sort(v.begin(), v.end());
  int sz = v.size();
  int q;
  cin >> q;
  int lo, hi;
  while (q--) {
    cin >> lo >> hi;
    int ind = upper_bound(v.begin(), v.end(), hi) - v.begin();
    if (v[ind - 1] >= lo)
      cout << v[ind - 1] << endl;
    else
      cout << -1 << endl;
  }
}
