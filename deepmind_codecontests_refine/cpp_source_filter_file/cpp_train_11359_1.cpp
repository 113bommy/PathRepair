#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
const double eps = (1e-10);
long long n, x, f, arr[200005];
int bs(int m) {
  if (m <= f) return 1;
  int st = 1, en = (m + x - 1) / x;
  while (st < en) {
    int mid = (st + en) >> 1;
    if ((m - f * mid) / x <= mid)
      en = mid;
    else
      st = mid + 1;
  }
  return st;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(10);
  long long sum = 0;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) cin >> arr[i];
  cin >> x >> f;
  long long ans = 0;
  for (int i = 0; i < (int)(n); ++i)
    if (arr[i] > x) {
      arr[i] -= x;
      ans += f * bs(arr[i]);
    }
  cout << ans;
  return 0;
}
