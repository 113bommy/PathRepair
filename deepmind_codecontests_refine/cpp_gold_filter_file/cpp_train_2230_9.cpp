#include <bits/stdc++.h>
using namespace std;
long long n, m, i, a[1000001], l, r, ans;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0)
      l++;
    else
      r++;
  }
  if (l < r) {
    for (i = 1; i <= n; i++) {
      if (a[i] == 0)
        l--;
      else
        ans += l;
    }
  } else {
    for (i = n; i >= 1; i--) {
      if (a[i] == 1)
        r--;
      else
        ans += r;
    }
  }
  cout << ans;
  return 0;
}
