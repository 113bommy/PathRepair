#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v;
  int x, y, z, a, b, c;
  int x1, y1;
  cout << "and 1 2" << endl;
  cin >> x1;
  cout << "or 1 2" << endl;
  cin >> y1;
  x = x1 + y1;
  cout << "and 3 2" << endl;
  cin >> x1;
  cout << "or 3 2" << endl;
  cin >> y1;
  z = x1 + y1;
  cout << "and 1 3" << endl;
  cin >> x1;
  cout << "or 1 3" << endl;
  cin >> y1;
  y = x1 + y1;
  a = (x - z + y) / 2;
  b = (z - y + x) / 2;
  c = (y + z - x) / 2;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  for (int i = 4; i <= n; i++) {
    cout << "and 1 " << i << endl;
    cin >> x1;
    cout << "or 1 " << i << endl;
    cin >> y1;
    x = x1 + y1;
    v.push_back(x - a);
  }
  sort(v.begin(), v.end());
  cout << "finish " << v[k - 1] << endl;
}
