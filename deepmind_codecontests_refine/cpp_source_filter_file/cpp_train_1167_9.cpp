#include <bits/stdc++.h>
using namespace std;
vector<int> v[1010];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x, y, Max = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> x >> y, v[x].push_back(y), Max = max(Max, x);
    for (int i = 1; i <= Max; i++) sort(v[i].begin(), v[i].end());
    string s;
    int Y = 0;
    bool check = true;
    for (int i = 0; i <= Max; i++) {
      if (!v[i].size()) {
        s += 'R';
        continue;
      } else {
        for (int j = 0; j < v[i].size(); j++)
          if (v[i][j] < Y) check = false;
        for (int j = Y; j < v[i][v[i].size() - 1]; j++) s += 'U';
        Y = v[i][v[i].size() - 1];
        if (i != Max) s += 'R';
      }
    }
    if (!check)
      cout << "NO" << '\n';
    else {
      cout << "YES" << '\n';
      cout << s << '\n';
    }
    for (int i = 0; i <= Max; i++) v[i].clear();
  }
  return 0;
}
