#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, x, y, z;
  cin >> x >> y >> z;
  a = x + y + c;
  b = x + x + y + y;
  c = x + x + z + z;
  d = y + y + z + z;
  vector<int> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  v.push_back(d);
  sort(v.begin(), v.end());
  cout << v[0] << endl;
  return 0;
}
