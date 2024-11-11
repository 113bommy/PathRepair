#include <bits/stdc++.h>
using namespace std;
vector<int> X;
map<int, vector<pair<int, int> > > Map;
vector<int> Pos;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  X.resize(n);
  for (int i = 0; i < n; i++) scanf("%d", &X[i]);
  sort(X.begin(), X.end());
  X.push_back(1000000000);
  for (int i = 0; i < m; i++) {
    int x1, x2, y;
    scanf("%d %d %d", &x1, &x2, &y);
    Map[y].push_back({x1, x2});
  }
  for (auto x : Map) {
    auto v = x.second;
    if (v.size() == 0) continue;
    sort(v.begin(), v.end());
    int Last = 1;
    for (auto y : v) {
      if (y.first != Last) break;
      Last = y.second;
    }
    Pos.push_back(Last);
  }
  sort(Pos.begin(), Pos.end());
  int Ans = INT_MAX;
  for (int i = 0; i < X.size(); i++) {
    int pos = lower_bound(Pos.begin(), Pos.end(), X[i]) - Pos.begin();
    pos = Pos.size() - pos;
    Ans = min(Ans, i + pos);
  }
  cout << Ans << endl;
}
