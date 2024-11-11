#include <bits/stdc++.h>
using namespace std;
long long oo = (long long)(1e18);
int a[(long long)(3e5 + 15)];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  int os = 0, op = 0;
  int es = 0, ep = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int in;
    cin >> in;
    if (i % 2 == 0)
      es += in;
    else
      os += in;
    a[i] = in;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      if (ep + os == op + es - a[i]) ans++;
      es -= a[i];
      ep += a[i];
    } else {
      if (op + es == ep + os - a[i]) ans++;
      os -= a[i];
      op += a[i];
    }
  }
  cout << ans;
  return 0;
}
