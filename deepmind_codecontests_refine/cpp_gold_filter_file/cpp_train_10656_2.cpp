#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<long long, long long>> lr;
  for (int i = 0; i < n; ++i) {
    long long l;
    cin >> l;
    long long r;
    cin >> r;
    ;
    lr.push_back({l, r});
  }
  vector<pair<long long, long long>> cop(lr);
  sort(cop.begin(), cop.end());
  long long b = cop[0].first;
  long long e = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (lr[i].second > e && lr[i].first == b) {
      e = lr[i].second;
      ans = i + 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (lr[i].second > e) {
      ans = -1;
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}
