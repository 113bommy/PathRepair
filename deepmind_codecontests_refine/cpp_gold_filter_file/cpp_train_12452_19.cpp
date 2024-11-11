#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p, a;
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == 'P') p.push_back(i);
    if (c == '*') a.push_back(i);
  }
  auto ok = [&](int x) {
    int j = (int)a.size() - 1;
    for (int i = (int)p.size() - 1; i >= 0 && j >= 0; --i) {
      if (abs(a[j] - p[i]) > x) continue;
      int l = (a[j] < p[i] ? p[i] - x
                           : min(p[i] - max(0, x - 2 * (a[j] - p[i])),
                                 p[i] - max(0, (x - a[j] + p[i]) / 2)));
      while (j >= 0 && a[j] >= l) --j;
    }
    return j == -1;
  };
  int lo = 1, hi = 2 * n;
  while (hi != lo) {
    int mid = (hi + lo) / 2;
    if (ok(mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << '\n';
}
