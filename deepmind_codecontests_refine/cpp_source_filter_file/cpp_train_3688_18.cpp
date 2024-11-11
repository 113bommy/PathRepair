#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, b, ans = 0;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n - 1; i++) cin >> a[i];
  cin >> c >> b;
  for (int i = 1; i <= b - c; i++) ans += a[i];
  cout << ans;
}
