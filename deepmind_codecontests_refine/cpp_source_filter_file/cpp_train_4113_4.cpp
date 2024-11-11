#include <bits/stdc++.h>
using namespace std;
int t[405];
int main() {
  memset(t, -1, sizeof t);
  vector<pair<int, pair<int, int> > > v;
  int n;
  cin >> n;
  int p;
  for (int x = 2; x <= 2 * n; x++) {
    for (int y = 1; y < x; y++) {
      cin >> p;
      v.push_back(make_pair(p, make_pair(x, y)));
    }
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  pair<int, pair<int, int> > at;
  for (int x = 0; x < v.size(); x++) {
    at = v[x];
    if (t[at.second.first] != -1 || t[at.second.second] != -1) continue;
    t[at.second.first] = at.second.second;
    t[at.second.second] = at.second.first;
  }
  for (int x = 1; x <= 2 * n; x++) {
    if (x != 1) cout << " ";
    cout << t[x];
  }
  cout << "\n";
  return 0;
}
