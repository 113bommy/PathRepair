#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int max = v[v.size() - 1];
  vector<int> res;
  res.push_back(0);
  for (int i = v.size() - 2; i >= 0; i--) {
    if (max > v[i]) {
      res.push_back(max - v[i] + 1);
    } else {
      res.push_back(0);
      max = v[i];
    }
  }
  reverse(res.begin(), res.end());
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}
