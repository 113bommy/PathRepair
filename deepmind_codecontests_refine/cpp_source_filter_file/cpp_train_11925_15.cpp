#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int t, cnt = 0;
  t = 1;
  while (t < n) {
    t *= 7;
    cnt++;
  }
  t = 1;
  while (t < m) {
    t *= 7;
    cnt++;
  }
  if (cnt > 7) {
    cout << "0\n";
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      bool mark[7] = {false}, fuck = false;
      int x = 0;
      t = i;
      while (t && !fuck) {
        if (!mark[t % 7])
          mark[t % 7] = true;
        else
          fuck = true;
        t /= 7;
        x++;
      }
      t = j;
      while (t && !fuck) {
        if (!mark[t % 7])
          mark[t % 7] = true;
        else
          fuck = true;
        t /= 7;
        x++;
      }
      if (x + 1 < cnt || (x + 1 == cnt && mark[0])) fuck = true;
      if (!fuck) ans++;
    }
  cout << ans << '\n';
  return 0;
}
