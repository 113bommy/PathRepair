#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = 1000000;
  for (int x = 1; x <= n; x++) {
    int elc = 0;
    for (int i = 1; i <= n; i++) {
      if (x >= i)
        elc += 4 * (x - 1) * a[i];
      else
        elc += 4 * (i - 1) * a[i];
    }
    ans = ans > elc ? elc : ans;
  }
  cout << ans << endl;
  return 0;
}
