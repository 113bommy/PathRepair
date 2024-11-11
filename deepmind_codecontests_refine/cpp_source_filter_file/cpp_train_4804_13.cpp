#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int d = k % 1000;
  d = 1000 - d;
  vector<int> ans(999, 0);
  if (k == 999999999)
    ans[998] = -1;
  else
    ans.push_back(-1);
  k = (k + 1000) / 1000;
  k++;
  int last = min(1000000, k), last2 = max(0, k - 1000000);
  for (int i = 0; i + 2 < d; i++) ans.push_back(0);
  if (last2 && d == 1) {
    for (int i = 0; i < 997; i++) ans.push_back(0);
    ans.push_back(2);
    ans.push_back(1000000);
  } else {
    if (d > 1) ans.push_back(last2);
    ans.push_back(last);
  }
  cout << ans.size() << endl;
  for (int i : ans) cout << i << " ";
  cin >> k;
}
