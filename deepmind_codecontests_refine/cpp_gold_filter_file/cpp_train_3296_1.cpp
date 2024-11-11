#include <bits/stdc++.h>
using namespace std;
int d[300], sz;
vector<pair<int, int> > edge;
void rec(int l, int r) {
  if (l > r) {
    sz++;
    return;
  }
  if (l == r) {
    sz = d[r] - d[l - 1] + 1;
    for (int j = 1; j <= sz; j++) {
      for (int i = j + 1; i <= sz; i++) {
        edge.push_back({j, i});
      }
    }
    return;
  }
  rec(l + 1, r - 1);
  sz += d[r] - d[r - 1];
  int t = d[l];
  if (l) t -= d[l - 1];
  for (int j = 1; j <= t; j++) {
    for (int i = 1; i < sz + j; i++) edge.push_back({j + sz, i});
  }
  sz += t;
}
int main() {
  int n;
  cin >> n;
  for (int j = 0; j < n; j++) {
    cin >> d[j];
  }
  rec(0, n - 1);
  cout << edge.size() << '\n';
  for (int j = 0; j < edge.size(); j++) {
    cout << edge[j].first << ' ' << edge[j].second << '\n';
  }
}
