#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, y, z;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> x >> y >> z;
    vector<int> v = {x, y, z};
    sort(v.begin(), v.end());
    cout << v[1] << endl;
  }
  return 0;
}
