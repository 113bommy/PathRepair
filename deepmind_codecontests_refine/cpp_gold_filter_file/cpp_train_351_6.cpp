#include <bits/stdc++.h>
using namespace std;
int n;
int a[100100];
long long x;
int ma;
long long sum;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ma = max(ma, a[i]);
    sum += 1ll * a[i];
  }
  int l = ma - 1, r = 2000000005;
  int mid;
  while (l + 1 < r) {
    mid = (1ll * l + r) / 2;
    x = 1ll * mid * n - sum;
    if (x >= mid)
      r = mid;
    else
      l = mid;
  }
  cout << r;
  return 0;
}
