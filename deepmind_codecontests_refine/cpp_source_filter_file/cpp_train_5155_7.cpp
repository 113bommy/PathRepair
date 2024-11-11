#include <bits/stdc++.h>
using namespace std;
long long a[200000], mn, z, n;
int main() {
  cin >> n;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  mn = a[0];
  z = 0;
  for (long long i = 0; i < n; ++i) {
    if (a[i] < mn) {
      mn = a[i];
      z = i;
    }
  }
  long long res = 0, cnt = 0;
  for (int i = z + 1; i != z; i = (i + 1) % n) {
    if (a[i] == mn) {
      res = max(res, cnt);
      cnt = 0;
    } else {
      ++cnt;
    }
  }
  res = max(res, cnt);
  cout << res + mn * n << endl;
  return 0;
}
