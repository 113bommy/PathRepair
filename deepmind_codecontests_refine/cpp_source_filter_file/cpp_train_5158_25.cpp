#include <bits/stdc++.h>
using namespace std;
int a[5], b[5], n, m, ans = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    a[i % 5]++;
  }
  for (int i = 1; i <= m; i++) {
    b[i % 5]++;
  }
  for (int i = 0; i < 5; i++) {
    ans += a[i] * b[(5 - i) % 5];
  }
  cout << ans << endl;
  return 0;
}
