#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
int main() {
  int n;
  cin >> n;
  int ans = 1000000000;
  int a[maxn];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int d = max(i - 1, n - i);
    ans = min(ans, a[i] / d);
  }
  cout << ans << endl;
  return 0;
}
