#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  cin >> n >> a >> b;
  vector<int> ans;
  ans.push_back(1);
  int x = 2;
  int idx = 1;
  int sum = 1;
  for (int i = 1; i <= b; i++) {
    ans.push_back(x);
    sum = x;
    x *= 2;
    idx++;
  }
  if (idx > n)
    cout << -1 << '\n';
  else {
    if (b == 0) {
      sum += 0;
      ans.push_back(sum);
      sum++;
      idx++;
    } else
      sum++;
    for (int i = 0; i < a; i++) {
      ans.push_back(sum);
      sum++;
      idx++;
    }
    if (idx > n)
      cout << -1 << '\n';
    else {
      for (int i = 0; i < n - idx; i++) ans.push_back(1);
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        cout << (i == (int)ans.size() - 1 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
