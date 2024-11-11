#include <bits/stdc++.h>
using namespace std;
int n;
int a[111111];
int b[111111];
int ans[111111];
int main() {
  cin >> n;
  int i;
  int ma = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    ma = max(ma, b[i]);
  }
  int tot = 0;
  for (i = 30; i >= 0; i--) {
    tot = 0;
    int temp = -1;
    for (int j = i; j <= n; j++) {
      if (a[j] & (1 << i)) {
        tot++;
        ans[tot] = a[j];
        if (temp == -1)
          temp = a[j];
        else
          temp &= a[j];
      }
    }
    if (temp % (1 << i) == 0) break;
  }
  cout << tot << endl;
  for (i = 1; i <= tot; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
