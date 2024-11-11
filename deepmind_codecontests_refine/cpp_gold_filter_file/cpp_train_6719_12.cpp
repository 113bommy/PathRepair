#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n;
  cin >> n >> a;
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int yu = min(abs(1 - a), abs(n - a));
  int ans = 0;
  for (int i = 1; i <= yu; i++) {
    if (b[a - i] == b[a + i]) {
      ans += b[a - i] + b[a + i];
      b[a - i] = 0;
      b[a + i] = 0;
    } else {
      b[a - i] = 0;
      b[a + i] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += b[i];
  }
  cout << ans;
}
