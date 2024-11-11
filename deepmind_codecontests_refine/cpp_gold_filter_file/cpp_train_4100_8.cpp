#include <bits/stdc++.h>
using namespace std;
#pragma(comment, linker("\STACK:50000000"))
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = a[i].first + 1;
    int cur = 4;
    while (cur < a[i].second) {
      cur *= 4;
      ++x;
    }
    ans = max(ans, x);
  }
  cout << ans;
}
