#include <bits/stdc++.h>
using namespace std;
long long ask(int t, int i, int j, int k) {
  cout << t << " " << i << " " << j << " " << k << endl;
  long long ret;
  cin >> ret;
  return ret;
}
int main() {
  int pos1 = 1, pos2 = 2;
  int n;
  cin >> n;
  for (int i = 3; i <= n; i++) {
    int x = ask(2, pos1, pos2, i);
    if (x == -1) pos2 = i;
  }
  vector<pair<long long, int>> v;
  for (int i = 2; i <= n; i++) {
    if (i == pos2) continue;
    long long x = ask(1, pos1, pos2, i);
    v.push_back({x, i});
  }
  sort(v.begin(), v.end());
  vector<int> lft, rgt;
  rgt.push_back(pos1);
  rgt.push_back(pos2);
  for (int i = 0; i + 1 < v.size(); i++) {
    long long x = ask(2, pos1, v[i].second, v[i + 1].second);
    if (x > 0)
      lft.push_back(v[i].second);
    else
      rgt.push_back(v[i].second);
  }
  rgt.push_back(v.back().second);
  cout << 0;
  for (int u : rgt) cout << " " << u;
  reverse(lft.begin(), lft.end());
  for (int u : lft) cout << " " << u;
  cout << endl;
  return 0;
}
