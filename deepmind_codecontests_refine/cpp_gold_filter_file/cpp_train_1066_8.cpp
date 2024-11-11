#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
void solve() {
  int n, x, m;
  cin >> n >> x >> m;
  int start = 0;
  int end = 0;
  int index = -1;
  int flag = 0;
  vector<pair<int, int>> range;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    range.push_back(make_pair(l, r));
    if ((l <= x && x <= r) && (flag != -1)) {
      index = i;
      flag = -1;
    }
  }
  if (index == -1)
    cout << "1" << endl;
  else {
    start = range[index].first;
    end = range[index].second;
    for (int i = index + 1; i < m; i++) {
      if (range[i].second >= start) start = min(range[i].first, start);
      if (range[i].first <= end) {
        end = max(end, range[i].second);
      }
    }
    cout << end - start + 1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t) {
    solve();
    --t;
  }
  return 0;
}
