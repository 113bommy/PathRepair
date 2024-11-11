#include <bits/stdc++.h>
using namespace std;
int w, h;
long long ans = 0;
int main() {
  cin >> w >> h;
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= w; j++) {
      int l = min(i, h - i);
      int r = min(j, w - j);
      ans += l * r;
    }
  }
  cout << ans;
  return 0;
}
