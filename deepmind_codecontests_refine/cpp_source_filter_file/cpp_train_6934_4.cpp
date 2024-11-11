#include <bits/stdc++.h>
using namespace std;
int n, a[1000006] = {0}, i, ans = 0, visi[1000006] = {0}, sum = 0;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (i = 0; i < n; ++i) cin >> a[i], visi[a[i]] = n;
  for (i = n - 1; i >= 0; --i) {
    sum += visi[a[i]] - i;
    visi[a[i]] = i;
    ans += sum;
  }
  cout << fixed << setprecision(10);
  double d = 2 * ans - n, t = n, tt = d / (t * t);
  cout << tt;
  return 0;
}
