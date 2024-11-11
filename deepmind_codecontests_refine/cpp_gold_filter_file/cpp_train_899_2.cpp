#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;
int n;
set<pair<int, int> > my;
vector<pair<int, int> > v;
void solve(int s, int e) {
  if (s >= e) {
    return;
  }
  solve(s, (s + e) / 2);
  solve((s + e) / 2 + 1, e);
  int x = v[(s + e) / 2].first;
  pair<int, int> help;
  help.first = x;
  for (int i = s; i < e; i++) {
    help.second = v[i].second;
    my.insert(help);
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pair<int, int> help;
    help.first = x;
    help.second = y;
    my.insert(help);
    v.push_back(help);
  }
  sort(v.begin(), v.end());
  solve(0, n);
  cout << my.size() << endl;
  for (set<pair<int, int> >::iterator it = my.begin(); it != my.end(); it++) {
    cout << (*it).first << " " << (*it).second << endl;
  }
}
