#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> xi, vector<int> yi, int s) {
  bool noa = true;
  for (int i = 0; i != xi.size(); ++i) {
    if (s >= xi[i]) noa = false;
  }
  if (noa) {
    bool equal = false;
    for (int i = 0; i != xi.size(); ++i) {
      if (xi[i] == s && yi[i] == 0) equal = true;
    }
    if (equal) return 0;
    return -1;
  }
  int max = 0;
  for (int i = 0; i != yi.size(); ++i) {
    if (s > xi[i] && yi[i] != 0 && 100 - yi[i] >= max) max = 100 - yi[i];
  }
  return max;
}
int main() {
  int n, s, x, y;
  cin >> n >> s;
  vector<int> xi, yi;
  for (int i = 0; i != n; ++i) {
    cin >> x >> y;
    xi.push_back(x);
    yi.push_back(y);
  }
  cout << solve(xi, yi, s) << endl;
  return 0;
}
