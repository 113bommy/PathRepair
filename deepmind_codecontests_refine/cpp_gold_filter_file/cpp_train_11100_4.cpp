#include <bits/stdc++.h>
using namespace std;
int n, a[505], cnt[505];
long long k;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int mx = a[0], mxi = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] > mx) mxi = i, mx = a[i];
    if (++cnt[mxi] == k) return cout << mx, 0;
  }
  cout << mx;
}
