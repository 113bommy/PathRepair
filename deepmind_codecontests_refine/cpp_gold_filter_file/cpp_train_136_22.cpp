#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(NULL);
  cin >> a >> b >> c;
  if (a <= b) return cout << 0, 0;
  long long ans = 0;
  for (long long l = 0, r = a * c, mid = 0; l < r;) {
    mid = (l + r) >> 1;
    if (a * c <= b * (mid + c)) {
      r = mid;
      ans = mid;
    } else
      l = mid + 1;
  }
  cout << ans;
}
