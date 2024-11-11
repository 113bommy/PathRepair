#include <bits/stdc++.h>
using namespace std;
bool sort_1(pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; }
bool sort_2(pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; }
int main() {
  int n, cnt = 0;
  scanf("%d", &n);
  vector<vector<pair<int, int>>> a(1000);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[x / 1000].push_back(make_pair(y, i + 1));
  }
  bool b = true;
  for (int i = 0; i < n; ++i) {
    if (b)
      sort(a[i].begin(), a[i].end(), sort_1);
    else
      sort(a[i].begin(), a[i].end(), sort_2);
    b = !b;
  }
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < a[i].size(); ++j) cout << a[i][j].second << " ";
  }
  return 0;
}
