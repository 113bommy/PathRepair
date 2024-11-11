#include <bits/stdc++.h>
using namespace std;
int main() {
  int Q, n, a[1003];
  cin >> Q;
  for (int test = 0; test < Q; ++test) {
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int k = 1; k <= n; ++k) cin >> a[k];
    sort(a, a + n);
    int ans = 1001;
    int ans1 = 1;
    for (int i = n; i > 0; --i) {
      int tmp = min(min(ans, a[i]), n - i + 1);
      ans1 = max(ans1, tmp);
    }
    cout << ans1 << endl;
  }
  return 0;
}
