#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100007], b[100007];
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int maxi = 0;
  for (int i = n; i >= 1; --i) {
    b[i] = maxi;
    maxi = max(maxi, a[i]);
  }
  for (int i = 1; i <= n; ++i)
    if (a[i] < b[i])
      cout << abs(a[i] - b[i]) + 1 << " ";
    else
      cout << 0 << " ";
}
