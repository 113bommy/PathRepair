#include <bits/stdc++.h>
using namespace std;
int n;
string s;
bool inc[205];
vector<int> ans;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if ('B' == s[i]) {
      inc[i + 1] = 1;
    } else
      inc[i + 1] = 0;
  }
  bool cop[205];
  for (int i = 1; i <= n; i++) cop[i] = inc[i];
  for (int i = 1; i < n; i++) {
    if (cop[i]) {
      cop[i] = 0;
      cop[i + 1] = !cop[i + 1];
      ans.push_back(i);
    }
  }
  if (cop[n]) {
    ans.clear();
    for (int i = 1; i < n; i++) {
      if (!inc[i]) {
        inc[i] = 1;
        inc[i + 1] = !cop[i + 1];
        ans.push_back(i);
      }
    }
    if (!inc[n]) {
      cout << -1;
      return 0;
    }
  }
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  return 0;
}
