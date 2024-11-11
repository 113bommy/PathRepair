#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cyc;
int main(void) {
  int n;
  cin >> n;
  if (n & 1) {
    cyc.push_back(vector<int>{1, 2, 3});
    cyc.push_back(vector<int>{1, 2, 3});
  } else {
    cyc.push_back(vector<int>{1, 2, 3, 4});
    cyc.push_back(vector<int>{1, 2, 4, 3});
    cyc.push_back(vector<int>{1, 4, 2, 3});
  }
  for (int i = 6 - (n & 1); i <= n; i += 2) {
    for (int j = 2; j <= n - 2; ++j)
      cyc.push_back(vector<int>{i - 1, j - 1, i, j});
    cyc.push_back(vector<int>{i - 1, 1, i});
    cyc.push_back(vector<int>{i - 1, i - 2, i});
  }
  cout << cyc.size() << "\n";
  for (vector<int>& _cyc : cyc) {
    cout << _cyc.size() << " ";
    for (int x : _cyc) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
