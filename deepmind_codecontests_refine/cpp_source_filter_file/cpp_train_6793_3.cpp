#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, p, ans[200005], count = 0, product, places, i, j, x;
  cin >> n >> p;
  long long a[n + 2];
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (x = a[n] + a[n]; x > 0; x--) {
    j = x;
    product = 1;
    for (i = n; i > 0; i--, j--) {
      if (j < a[i]) break;
      places = min(i, j - a[i] + 1);
      product = product * places % p;
    }
    if (i != 0) break;
    if (product % p != 0) ans[count++] = x - n + 1;
  }
  cout << count << endl;
  for (i = count - 1; i >= 0; i--) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
