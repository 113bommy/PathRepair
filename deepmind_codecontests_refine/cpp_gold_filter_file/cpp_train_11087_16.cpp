#include <bits/stdc++.h>
using namespace std;
int ans[100001];
int a[100001];
int main() {
  int n, i, max1;
  cin >> n;
  max1 = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = n; i >= 1; i--) {
    if (max1 > a[i]) {
      ans[i - 1] = max1;
    } else {
      ans[i - 1] = a[i];
      max1 = a[i];
    }
  }
  for (i = 1; i <= n; i++) {
    if (i != 1) cout << " ";
    if (a[i] <= ans[i])
      cout << ans[i] - a[i] + 1;
    else
      cout << 0;
  }
  cout << endl;
  return 0;
}
