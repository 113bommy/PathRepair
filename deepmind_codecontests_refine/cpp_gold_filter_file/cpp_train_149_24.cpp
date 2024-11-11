#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vn(n), vm(m);
  for (int i = 0; i < n; i++) cin >> vn[i];
  vector<int> s;
  vector<bool> vis(n, false);
  for (int i = 0; i < m; i++) {
    cin >> vm[i];
    if (!vis[vm[i]]) {
      s.push_back(vm[i]);
      vis[vm[i]] = true;
    }
  }
  int res = 0;
  for (int i = 0; i < m; i++) {
    int j, x;
    for (j = 0; j < s.size(); j++) {
      if (s[j] == vm[i]) {
        x = s[j];
        break;
      }
    }
    j--;
    for (; j >= 0; j--) {
      s[j + 1] = s[j];
      res += vn[s[j] - 1];
    }
    s[0] = x;
  }
  cout << res;
  return 0;
}
