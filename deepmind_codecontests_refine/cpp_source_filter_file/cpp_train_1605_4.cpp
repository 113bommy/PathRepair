#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], sum, ans, sum1, hasil(1e18), l, r, wl, wr;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l >> r >> wl >> wr;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i <= n; i++) {
    sum -= a[i];
    ans += a[i];
    if (n - i > i) {
      sum1 = (n - 2 * i - 1) * wr;
    } else if (n - 1 < i) {
      sum1 = (2 * i - n - 1) * wl;
    } else {
      sum1 = 0;
    }
    hasil = min(hasil, ans * l + sum * r + sum1);
  }
  cout << hasil << '\n';
  return 0;
}
