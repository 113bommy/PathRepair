#include <bits/stdc++.h>
using namespace std;
int n, res, a;
int main() {
  res = 0;
  vector<int> v;
  cin >> n;
  if (n == 1) {
    cin >> a;
    cout << a << endl;
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a;
    v.push_back(a);
  }
  for (int i = 0; i < v.size(); ++i) {
    int xp = 0;
    for (int j = i; j < v.size(); ++j) {
      xp ^= v[j];
      res = max(res, xp);
    }
  }
  cout << res << endl;
  return 0;
}
