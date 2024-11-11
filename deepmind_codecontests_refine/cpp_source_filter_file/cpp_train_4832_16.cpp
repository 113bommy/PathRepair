#include <bits/stdc++.h>
using namespace std;
long long mn = (long long)(1e9);
long long n, ans, k, a[311111], near[1111111], x;
bool mark[1111111];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mark[a[i]] = 1;
    mn = min(mn, a[i]);
  }
  for (int i = 1; i <= 1000000; i++) {
    near[i] = x;
    if (mark[i]) x = i;
  }
  for (int i = mn; i >= 1; i--) {
    long long mx = -(long long)(1e9);
    for (int j = 0; j <= 1000000; j += i) {
      if (near[j + i] >= j) mx = max(mx, near[j + i] - j);
    }
    if (mx != -(long long)(1e9) && mx <= k) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
