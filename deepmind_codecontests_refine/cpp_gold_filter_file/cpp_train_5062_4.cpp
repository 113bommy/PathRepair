#include <bits/stdc++.h>
using namespace std;
int n, m, temp, v;
vector<int> a[100002];
vector<int> e;
vector<int> t[100002];
set<int> caps, lowers;
void dfs(int i) {
  for (int a : t[i]) {
    if (caps.count(a)) continue;
    caps.insert(a);
    dfs(a);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    for (int j = 0; j < temp; j++) {
      cin >> v;
      a[i].push_back(v);
    }
  }
  for (int i = 1; i < n; i++) {
    bool n = false;
    for (int j = 0; j < a[i].size(); j++) {
      if (j >= a[i - 1].size()) {
        n = true;
        break;
      } else if (a[i - 1][j] != a[i][j]) {
        n = true;
        if (a[i - 1][j] < a[i][j]) {
          e.push_back(a[i][j]);
          e.push_back(a[i - 1][j]);
          t[a[i][j]].push_back(a[i - 1][j]);
        } else {
          caps.insert(a[i - 1][j]);
          lowers.insert(a[i][j]);
        }
        break;
      }
    }
    if (n || a[i - 1].size() == a[i].size()) continue;
    cout << "No" << endl;
    return 0;
  }
  for (int i : caps) {
    dfs(i);
  }
  for (int i : lowers) {
    if (caps.count(i)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl << caps.size() << endl;
  for (int i : caps) {
    cout << i << " ";
  }
}
