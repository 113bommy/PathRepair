#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (!(n % 2)) {
    cout << -1;
    return 0;
  }
  if (n == 1) {
    cout << 0 << endl << 0 << endl << 0 << endl;
    return 0;
  }
  int os = n - 2;
  int es = n - 1;
  vector<int> f1, f2, res;
  for (int i = 0; i < n; i++) {
    f1.push_back(i);
    if (es < 0) {
      f2.push_back(os);
      os -= 2;
    } else {
      f2.push_back(es);
      es -= 2;
    }
    res.push_back(n - i - 1);
  }
  for (auto i : f1) {
    cout << i << " ";
  }
  cout << endl;
  for (auto j : f2) {
    cout << j << " ";
  }
  cout << endl;
  for (auto r : res) {
    cout << r << " ";
  }
  cout << endl;
  return 0;
}
