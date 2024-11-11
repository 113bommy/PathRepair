#include <bits/stdc++.h>
using namespace std;
int n, k, a[2000000];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int res = -1;
  int r = 1;
  for (int i = n; i >= 1; i--) {
    if ((k - 1) * 2 >= i - 1)
      res = max(res, a[i]), k--;
    else
      k--, res = max(res, a[i] + a[r]), r++;
  }
  cout << res;
}
