#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ans;
  int i = 1;
  while (m > 0 && i <= n) {
    if (m >= (i - 1) / 2) {
      ans.push_back(i);
      m -= (i - 1) / 2;
    } else {
      ans.push_back(ans.back() + i - 1 - 2 * m);
      m = 0;
    }
    i++;
  }
  if (m > 0)
    cout << -1;
  else {
    i = 1;
    int x = n;
    if (ans.size() > 0) {
      i = ans.back() + 1;
      x = ans.back() + i;
    }
    while (ans.size() < n) {
      ans.push_back(x);
      x += i;
    }
    for (auto it : ans) cout << it << " ";
  }
}
