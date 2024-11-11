#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  int a[n], i, sum = 0, ans = 0;
  float l = (float)(n)*4.5;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  i = 0;
  while (sum < l && i < n) {
    sum += 5 - a[i];
    ans++;
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
