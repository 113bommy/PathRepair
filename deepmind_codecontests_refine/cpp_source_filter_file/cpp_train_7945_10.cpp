#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, res = 0;
  cin >> n;
  vector<pair<int, int> > v(n);
  for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
  for (int i = 0; i < n; i++) {
    bool a, b, c, d;
    a = b = c = d = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (v[i].first > v[j].first && v[i].second == v[i].second) a = 1;
      if (v[i].first < v[j].first && v[i].second == v[i].second) b = 1;
      if (v[i].first == v[j].first && v[i].second < v[j].second) c = 1;
      if (v[i].first == v[j].first && v[i].second > v[j].second) d = 1;
      if (a && b && c && d) break;
    }
    if (a && b && c && d) res++;
  }
  cout << res << endl;
  return 0;
}
