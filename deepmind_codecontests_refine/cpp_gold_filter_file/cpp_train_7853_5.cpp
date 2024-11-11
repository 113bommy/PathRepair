#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, mn = 1 << 30, mx = 0, mncnt = 0, mxcnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a == mn) ++mncnt;
    if (a == mx) ++mxcnt;
    if (a < mn) {
      mn = a;
      mncnt = 1;
    }
    if (a > mx) {
      mx = a;
      mxcnt = 1;
    }
  }
  if (mn == mx) {
    cout << "0 " << mncnt * (mncnt - 1) / 2;
    return 0;
  }
  cout << mx - mn << " " << mxcnt * mncnt;
}
