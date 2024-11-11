#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:65777216")
using namespace std;
int n, d, a[1000], m;
int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  cin >> m;
  int ans = 0;
  for (int i = 1; i <= min(n, m); i++) {
    ans += a[i];
  }
  if (m > n) {
    ans -= d * (m - n);
  }
  cout << ans;
}
