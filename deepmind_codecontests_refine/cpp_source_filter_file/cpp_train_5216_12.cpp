#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, mx = 0, c = 1;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 1; i < n; i++) {
    if (a[i] <= 2 * a[i - 1])
      c++;
    else
      c = 1;
    mx = max(c, mx);
  }
  cout << mx;
  return 0;
}
