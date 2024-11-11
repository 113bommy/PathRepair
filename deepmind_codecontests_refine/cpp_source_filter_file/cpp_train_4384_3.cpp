#include <bits/stdc++.h>
using namespace std;
int w, h, k, a[111][111], ans;
int main() {
  cin >> w >> h >> k;
  for (int i = 0; i < k; ++i) ans += 2 * (w + h - 4 * i) - 4;
  cout << ans;
}
