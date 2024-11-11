#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > path;
vector<int> ans;
bool flag = 0;
void get_path(int y, int b) {
  ans.push_back(y);
  if (y == b)
    return;
  else {
    for (int i = 0; i < path.size(); i++) {
      if (path[i].second == y) {
        get_path(path[i].first, b);
      }
    }
  }
}
void dfs(int y, int l, int a, int b) {
  path.push_back(make_pair(l, y));
  if (y > a) {
    if (y % 2 == 0) {
      dfs(y / 2, y, a, b);
    } else {
      if ((y - 1) % 10 == 0) dfs((y - 1) / 10, y, a, b);
    }
  } else if (y == a) {
    flag = 1;
    ans.push_back(y);
    get_path(l, b);
  }
}
int main() {
  int a, b;
  cin >> a >> b;
  dfs(b, b, a, b);
  if (flag == 1) {
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << ' ';
    }
  } else
    cout << "NO";
}
