#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long MAX = 6e6 + 10;
int w[1000];
int a[1000];
void solve() {
  int n;
  cin >> n;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    cin >> w[i];
    a[w[i]]++;
  }
  int ans = 0;
  for (int i = 2; i <= n * 2; i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++) {
      sum += min(a[j], a[i - j]);
    }
    ans = max(ans, sum / 2);
  }
  cout << ans << endl;
}
int main() {
  int _ = 1;
  cin >> _;
  while (_--) {
    solve();
  }
  return 0;
}
