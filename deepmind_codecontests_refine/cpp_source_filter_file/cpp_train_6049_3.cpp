#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
map<int, int> ph;
int main() {
  int n, a1, b;
  cin >> n >> a1 >> b;
  ph[0] = a1;
  ph[1] = b;
  int a[n + 5];
  int ans = 0;
  int flg = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n / 2 + 1; i++) {
    if (a[i] == 2 and a[n - i - 1] == 2 and i != n - i - 1)
      ans += 2 * min(a1, b);
    else if (a[i] == 2 and a[n - i - 1] == 2 and i == n - i - 1)
      ans += min(a1, b);
    else if (a[i] != 2 and a[n - i - 1] == 2)
      ans += ph[a[i]];
    else if (a[i] == 2 and a[n - i - 1] != 2)
      ans += ph[a[n - i - 1]];
    else if (a[i] != a[n - i - 1])
      flg = 1;
  }
  if (flg)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
