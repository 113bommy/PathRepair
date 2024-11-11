#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int main() {
  ios::sync_with_stdio(false);
  int n, a, b, k, f;
  cin >> n >> a >> b >> k >> f;
  map<pair<string, string>, int> cost;
  int totes = 0;
  string last = "";
  for (int i = 0; i < n; i++) {
    string x, y;
    cin >> x >> y;
    auto p = make_pair(min(x, y), max(x, y));
    if (x == last) {
      cost[p] += b;
      totes += b;
    } else {
      cost[p] += a;
      totes += a;
    }
    last = y;
  }
  vector<int> ed;
  for (auto& p : cost) {
    ed.emplace_back(p.second);
  }
  sort(ed.rbegin(), ed.rend());
  for (int i = 0; i < ed.size(); i++) {
    if (k && ed[i] > f) {
      k--;
      totes -= ed[i];
      totes += f;
    }
  }
  cout << totes << endl;
  return 0;
}
