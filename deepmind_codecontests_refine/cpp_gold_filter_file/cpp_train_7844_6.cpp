#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:400000000")
int n, a[111];
int main() {
  cin >> n;
  if (n < 3 || n % 2 == 0) {
    cout << -1;
    return 0;
  }
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  int ans = 0;
  for (int i = n; i >= 3; i -= 2) {
    int x = max(a[i], a[i - 1]);
    ans += x;
    a[i / 2] -= x;
    if (a[i / 2] < 0) a[i / 2] = 0;
  }
  cout << ans + a[1];
}
