#include <bits/stdc++.h>
using namespace std;
vector<string> level[1000005];
int mx = 0, n, req[100005];
string s;
int main() {
  ios_base::sync_with_stdio(0);
  string s1;
  cin >> s;
  req[1] = 1;
  int l = s.size(), neww = 0, flag = 0, n, parent = 1, mx = 0;
  for (int i = 0; i < l; i++) {
    mx = max(mx, parent);
    if (s[i] == ',') {
      i++;
      n = 0;
      while (s[i] >= '0' && s[i] <= '9') {
        n *= 10;
        n += (s[i] - '0');
        i++;
      }
      level[parent].push_back(s1);
      req[parent]--;
      if (n != 0) {
        req[parent + 1] = n;
        parent += 1;
      } else {
        while (req[parent] == 0 && parent > 1) parent -= 1;
      }
      s1.clear();
    } else
      s1 += s[i];
    req[1] = 1;
  }
  cout << mx << endl;
  for (int i = 1; i <= mx; i++) {
    for (int j = 0; j < level[i].size(); j++) {
      cout << level[i][j] << " ";
    }
    cout << endl;
  }
}
