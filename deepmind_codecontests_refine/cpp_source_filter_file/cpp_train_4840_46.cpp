#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> res;
  int k;
  cin >> n;
  vector<int> us(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> k;
      if (i != j && k % 2 == 1) {
        us[i] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (us[i] == 0) {
      res.push_back(i);
    }
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << ' ';
  }
  return 0;
}
