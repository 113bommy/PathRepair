#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a[1000]{};
  for (int i = 0; i < t; i++) {
    int n, s, k;
    cin >> n >> s >> k;
    set<int> b;
    for (int j = 0; j < k; j++) {
      cin >> a[j];
      b.insert(a[j]);
    }
    int ans = n;
    for (int i = max(1, s - k); i <= min(n, s + k + 1); i++) {
      if (b.count(i) == 0) {
        ans = min(ans, abs(s - i));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
