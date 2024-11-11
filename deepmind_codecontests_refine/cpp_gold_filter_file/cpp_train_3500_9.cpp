#include <bits/stdc++.h>
using namespace std;
bool used1[20];
bool used2[20];
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ans = min(ans, a);
    }
    cout << ans;
  } else if (k == 2) {
    vector<int> mn(n + 1, INT_MAX);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mn[i] = min(mn[i - 1], a[i]);
    }
    int ans = INT_MIN;
    int mnn = INT_MAX;
    for (int i = n; i > 1; i--) {
      mnn = min(mnn, a[i]);
      ans = max(ans, max(mn[i - 1], mnn));
    }
    cout << ans;
  } else {
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ans = max(ans, a);
    }
    cout << ans;
  }
  return 0;
}
