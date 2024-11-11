#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, h, i, j;
  long long ans = 0;
  cin >> w >> h;
  for (i = 0; i < w; i++)
    for (j = 0; j < h; j++) ans += min(w - j, j) * min(h - i, i);
  cout << ans;
  return 0;
}
