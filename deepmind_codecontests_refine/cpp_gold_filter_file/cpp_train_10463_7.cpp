#include <bits/stdc++.h>
using namespace std;
int a[201010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int ans = 0x3f3f3f3f;
  for (int i = 0; i + n / 2 < n; i++) ans = min(ans, a[i + n / 2] - a[i]);
  cout << ans << endl;
  return 0;
}
