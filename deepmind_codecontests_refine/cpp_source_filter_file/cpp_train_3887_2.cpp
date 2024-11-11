#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[102], sum = 0, ts = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    ts += a[i];
    ans++;
    if (ts > (sum + 1) / 2) break;
  }
  cout << ans << endl;
  return 0;
}
