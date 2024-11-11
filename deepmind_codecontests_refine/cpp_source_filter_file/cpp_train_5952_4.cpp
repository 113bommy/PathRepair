#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  q = 1;
  for (int t = 0; t < q; ++t) {
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    sort(cnt.rbegin(), cnt.rend());
    int ans = cnt[0];
    int lst = cnt[0];
    for (int i = 1; i <= n; ++i) {
      if (lst == 0) break;
      if (cnt[i] >= lst) {
        ans += lst - 1;
        lst -= 1;
      } else {
        ans += cnt[i];
        lst = cnt[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
