#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  map<int, int> a;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a[x]++;
  }
  int ans(0);
  for (int i(2); i <= int(1e5); i++) {
    int ma(0);
    for (int j(i); j <= int(1e5); j += i) {
      ma += a[j];
    }
    ans = max(ma, ans);
  }
  cout << ans;
  return 0;
}
