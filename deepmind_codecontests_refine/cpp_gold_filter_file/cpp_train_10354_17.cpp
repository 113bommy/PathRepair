#include <bits/stdc++.h>
using namespace std;
int a[100005], n;
bool isOk(int val) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0)
      s += (a[i] + val - a[i + 1]);
    else
      s += (a[i] - a[i + 1]);
    if (s < 0) return false;
  }
  if (s >= 0) return true;
  return false;
}
int main() {
  int ma = -1;
  cin >> n;
  a[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ma = max(ma, a[i]);
  }
  int lo = 0, hi = ma + 100, loop = 0;
  while (lo < hi && ++loop < 400) {
    int mid = (lo + hi) >> 1;
    if (isOk(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << hi << endl;
  return 0;
}
