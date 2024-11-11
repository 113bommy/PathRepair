#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<long long, long long>> pts;
bool check(long long x) {
  bool status = true;
  for (auto i : pts) {
    long long x1 = i.first;
    long long y1 = i.second;
    long long myx = i.first;
    long long myy = x - i.first;
    if (myy < y1) {
      status = false;
      break;
    }
  }
  return status;
}
long long binsearch(long long lo, long long hi) {
  while (lo < hi) {
    long long mid = (lo + hi) / 2;
    if (check(mid) == false) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return lo;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  pts.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].first >> pts[i].second;
  }
  sort(pts.begin(), pts.end());
  long long ans = binsearch(0, 1e9 + 1);
  cout << ans << endl;
  return 0;
}
