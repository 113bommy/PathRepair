#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int mx = 0;
    for (int j = 0; j < a[i]; j++) {
      int x;
      cin >> x;
      mx = max(mx, x);
    }
    b[i] = mx;
  }
  int mx = *max_element(b, b + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (long long)((mx - b[i]) * a[i]);
  }
  cout << ans << "\n";
}
