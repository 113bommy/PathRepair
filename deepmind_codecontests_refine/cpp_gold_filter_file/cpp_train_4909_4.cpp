#include <bits/stdc++.h>
using namespace std;
bitset<300000001> p;
int main() {
  int l, r;
  cin >> l >> r;
  for (int i = 3; i * i <= r; i += 2) {
    if (p[i]) continue;
    for (int j = i + i; j < r + 1; j += i) p[j] = 1;
  }
  int ans = (l <= 2 && r >= 2 ? 1 : 0);
  for (int i = 1; i * i <= r; i++) {
    for (int j = i + 1; j * j <= r; j += 2) {
      int T = i * i + j * j;
      if (T >= l && T <= r && !p[T]) ans++;
    }
  }
  cout << ans;
  return 0;
}
