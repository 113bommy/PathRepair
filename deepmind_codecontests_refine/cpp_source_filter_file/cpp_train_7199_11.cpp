#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1], b[n + 1];
  int p[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[a[i]] = 0;
  };
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    p[b[i]] = i;
  };
  if (p[1]) {
    int i;
    for (i = 2; p[i] == p[1] + i - 1; i++)
      ;
    if (p[i - 1] == n) {
      int j;
      for (j = i; j <= n && p[j] <= j - i + 1; j++)
        ;
      if (j > n) {
        cout << n - i + 1 << endl;
        return 0;
      }
    }
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, p[i] - i + 1 + n);
  }
  cout << ans << endl;
  return 0;
}
