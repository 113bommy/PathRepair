#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, a, b, t = -1, ans;
  cin >> x >> y;
  bool vis[100001];
  unordered_set<int> vec[100001];
  unordered_map<int, int> cc;
  for (int i = 1; i <= x; i++) {
    cin >> a;
    cc[i] = a;
    vis[a] = true;
  }
  for (int i = 0; i < y; i++) {
    cin >> a >> b;
    if (cc[a] != cc[b]) {
      vec[cc[a]].insert(cc[b]);
      vec[cc[b]].insert(cc[a]);
    }
  }
  for (int i = 1; i <= 10000; i++) {
    if ((int)vec[i].size() > t && vis[i]) {
      t = vec[i].size();
      ans = i;
    }
  }
  cout << ans;
}
