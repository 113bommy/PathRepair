#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, timer = 1;
  int l, r;
  int i, watchtime = 0;
  cin >> n >> x;
  for (i = 0; i < n; i++) {
    cin >> l >> r;
    if (i == 0) {
      timer += (((l - 1) / x) * x);
      watchtime += (r - timer + 1);
      timer = r + 1;
    } else {
      timer += (((l - timer) / x) * x);
      watchtime += r - timer + 1;
      timer = (r + 1);
    }
  }
  cout << watchtime;
  return 0;
}
