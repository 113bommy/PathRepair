#include <bits/stdc++.h>
using namespace std;
int w, h, k, a[111][111], ans;
int main() {
  cin >> w >> h >> k;
  for (int i = 0; i < k; ++i) ans += 2 * (w + h - 8 * i - 2);
  cout << ans;
}
