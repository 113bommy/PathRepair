#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans = 0;
  cin >> n >> m;
  for (int i = 0; i * i <= n; i++) {
    if ((n - i * i) * (n - i * i) + i == m) ans++;
  }
  cout << ans;
  return 0;
}
