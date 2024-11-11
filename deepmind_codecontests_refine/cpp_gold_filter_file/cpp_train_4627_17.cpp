#include <bits/stdc++.h>
using namespace std;
int a[2001];
int main() {
  int n, b;
  cin >> n >> b;
  int i, j;
  for (i = 1; i <= n; i++) cin >> a[i];
  int ans = b;
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) {
      int tmpans = b % a[i] + b / a[i] * a[j];
      ans = max(tmpans, ans);
    }
  cout << ans << endl;
  return 0;
}
