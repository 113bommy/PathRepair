#include <bits/stdc++.h>
using namespace std;
long long h, n, cant[64];
void prec() {
  cant[h] = 1;
  for (int i = h - 1; i >= 0; --i) cant[i] = cant[i + 1] << 1;
  for (int i = h - 1; i >= 0; --i) cant[i] += cant[i + 1];
}
int main() {
  cin >> h >> n;
  prec();
  long long l = 1, r = (1LL << h), lev = 0, ans = 0, f = 0;
  while (l != r) {
    ans++;
    long long mid = (l + r) >> 1;
    if (!f) {
      if (n <= mid)
        f ^= 1;
      else
        ans += cant[lev + 1];
    } else {
      if (n > mid)
        f ^= 1;
      else
        ans += cant[lev + 1];
    }
    lev++;
    if (n <= mid)
      r = mid;
    else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
