#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  int ans = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) v.push_back(a[i] - a[i - 1]);
  int x = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] == 1)
      x++, ans = max(ans, x - 1);
    else
      x = 0;
  }
  if (a[0] == 1) {
    x = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] - a[i - 1] == 1)
        x++;
      else
        break;
    }
    ans = max(ans, x);
  }
  if (a[n - 1] == 1000) {
    x = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] - a[i + 1] == -1)
        x++;
      else
        break;
    }
    ans = max(ans, x);
  }
  cout << ans;
}
