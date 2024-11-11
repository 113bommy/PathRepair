#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int a[2010], b[2010];
int main() {
  int n, m;
  cin >> n >> m;
  int cnt1 = 1, cnt2 = 1;
  for (int i = 1; i <= n; i++) {
    if (i % 2 != 0)
      a[cnt1++] = i;
    else
      b[cnt2++] = i;
  }
  int ans;
  if (m == 0)
    ans = 1;
  else if (m >= n / 2)
    ans = n - m;
  else
    ans = m;
  cout << ans << endl;
  return 0;
}
