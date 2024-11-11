#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, abc = 864197532, N = 100001, logN = 17;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int a, b, w, x, c;
  cin >> a >> b >> w >> x >> c;
  if (a >= c) {
    cout << 0 << endl;
    return 0;
  }
  long long int l = 0, r = 1ll << 50;
  while (r - l > 1) {
    long long int mid = l + r >> 1;
    if (c - mid <= a - (max(mid * x - b, 0ll) + w - 1) / w)
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
}
