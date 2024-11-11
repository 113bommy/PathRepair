#include <bits/stdc++.h>
using namespace std;
long long n, i, j, x, ar[1000004], a, cnt, pre, flg, ans, kp, mx;
int main() {
  while (cin >> n >> x) {
    mx = 0;
    for (i = 1; i <= n; i++) {
      cin >> a;
      ar[a]++;
      mx = max(mx, a);
    }
    cnt = 0;
    for (i = 0; i <= max(mx, x); i++) {
      if (ar[i] == 0 && i < x) ++cnt;
      if (i == x) {
        if (ar[i] != 0) ++cnt;
        break;
      }
      if (i > x) break;
    }
    memset(ar, 0, sizeof ar);
    cout << cnt << endl;
  }
  return 0;
}
