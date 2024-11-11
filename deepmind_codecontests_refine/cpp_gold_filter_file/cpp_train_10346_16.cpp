#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int d = a;
    if (b > k) d = a - (b - k);
    ans = max(ans, d);
  }
  cout << ans << "\n";
}
