#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, ans;
  vector<int> a;
  cin >> n;
  ans = 0;
  cin >> x;
  for (int i = 1; i < n; i++) {
    cin >> y;
    if (y == 1) {
      ans++;
      a.push_back(x);
    }
    x = y;
  }
  a.push_back(y);
  cout << a.size() << endl;
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}
