#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v[5005];
int n, m;
int dist(int x, int y) { return (y - x + n) % n; }
bool comp(pair<int, int> a, pair<int, int> b) {
  return dist(a.first, a.second) < dist(b.first, b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  int maxi = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a - 1].push_back(make_pair(a, b));
  }
  for (int i = 0; i < n; i++) {
    sort(v[i].begin(), v[i].end());
    maxi = max(maxi, int(v[i].size()));
  }
  for (int i = 1; i <= n; i++) {
    if (i == n) i = 0;
    int maxi = 0;
    for (int j = 0; j < n; j++) {
      int ind = v[j].size() - 1, last = i, x = 0;
      while (true) {
        if (ind < 0) break;
        int d;
        if (last == v[j][ind].first) {
          d = dist(last, v[j][ind].second);
          last = v[j][ind].second;
          ind -= 1;
        } else {
          d = dist(last, v[j][ind].first);
          last = v[j][ind].first;
        }
        x += d;
      }
      maxi = max(maxi, x);
    }
    cout << maxi << " ";
    if (!i) break;
  }
  return 0;
}
