#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long w, h, ans = 0;
  cin >> w >> h;
  for (long long i = 2; i <= w; i += 2) {
    for (long long j = 2; j < h; j += 2) {
      ans += (w - i + 1) * (h - j + 1);
    }
  }
  cout << ans;
  return 0;
}
