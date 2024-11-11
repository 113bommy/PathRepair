#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  unordered_map<int, int> mi, ma;
  mi[0] = 0;
  ma[0] = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      sum++;
    } else
      sum--;
    if (mi.find(sum) == mi.end()) mi[sum] = i;
    ma[sum] = i;
  }
  int res = 0;
  for (auto item : mi) {
    res = max(res, ma[item.first] - item.second);
  }
  cout << res << endl;
  return 0;
}
