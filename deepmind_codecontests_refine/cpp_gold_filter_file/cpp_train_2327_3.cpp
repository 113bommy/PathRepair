#include <bits/stdc++.h>
using namespace std;
map<int, int> a, b;
map<int, int>::iterator it;
int n, ans = 1000000, k;
int main() {
  int i, x, y, k;
  cin >> n;
  k = n / 2 + n % 2;
  for (i = 1; i <= n; i++) {
    cin >> x >> y;
    a[x]++;
    b[x]++;
    if (x != y) b[y]++;
  }
  for (it = b.begin(); it != b.end(); it++) {
    x = it->first;
    if (a[x] >= k)
      ans = 0;
    else if (b[x] >= k)
      ans = min(ans, min(b[x] - a[x], k - a[x]));
  }
  if (ans == 1000000)
    cout << "-1\n";
  else
    cout << ans << endl;
  return 0;
}
