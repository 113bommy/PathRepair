#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long a[n];
  long long ans = 0;
  long long nz = 0;
  long long minus = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > 0) {
      ans += a[i] - 1;
    } else if (a[i] < 0) {
      ans += -1 - a[i];
      minus++;
    } else {
      nz++;
    }
  }
  if (minus % 2 == 0)
    cout << ans + nz;
  else if (nz != 0)
    cout << ans + nz;
  else
    cout << ans + 2;
  return 0;
}
