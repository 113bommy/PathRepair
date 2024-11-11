#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n], e = 0, s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1)
      e++;
    else
      s++;
  }
  int ans = 0;
  for (int b = 0; b < k; b++) {
    int c = b, ee = e, second = s;
    while (c < n) {
      if (a[c] == 1)
        ee--;
      else
        second--;
      c += k;
    }
    ans = max(ans, abs(ee - second));
  }
  cout << ans;
}
