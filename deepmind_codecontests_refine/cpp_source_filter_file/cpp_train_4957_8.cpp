#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, T;
  cin >> n >> T;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }
  vector<pair<int, int>> segment;
  for (int i = 0; i < n; ++i) {
    int a = t[i] - i;
    int b = T - i - 1;
    if (a <= b) {
      segment.push_back({a, b});
    }
  }
  map<int, int> open, close;
  set<int> x;
  for (auto seg : segment) {
    ++open[seg.first];
    ++close[seg.second];
    x.insert(seg.first);
    x.insert(seg.second);
  }
  int ans = 0;
  int unclosed_num = 0;
  for (auto i : x) {
    unclosed_num += open[i];
    ans = max(ans, unclosed_num);
    unclosed_num -= close[i];
  }
  cout << ans << endl;
}
