#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int> > values(n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    values[i] = make_pair(a[i], i);
  }
  sort(values.begin(), values.end());
  vector<pair<int, int> > seg;
  for (int i = 0; i < n; ++i) {
    if (i + k - 1 < n && values[i].first == values[i + k - 1].first) {
      seg.push_back(make_pair(values[i + k - 1].second, values[i].second));
    }
  }
  sort(seg.begin(), seg.end());
  int ans = 0;
  for (int j = 0, i = 0; i < n; ++i) {
    while (j < seg.size() && seg[j].second < i) ++j;
    if (j < seg.size()) {
      ans += n - seg[j].first;
    }
  }
  cout << ans << endl;
  return 0;
}
