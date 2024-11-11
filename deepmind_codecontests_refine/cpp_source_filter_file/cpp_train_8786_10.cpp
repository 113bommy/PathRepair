#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x, y, cnt1 = 0, cnt2 = 0, j;
  cin >> n;
  int w[n + 1];
  for (i = 1; i <= n; i++) cin >> w[i];
  cin >> x >> y;
  for (j = 0; j < 10; j++) {
    cnt1 = 0, cnt2 = 0;
    for (i = 1; i <= n; i++) {
      if (i >= j)
        cnt1 += w[i];
      else
        cnt2 += w[i];
    }
    if (cnt1 >= x && cnt2 <= y && cnt1 <= y && cnt2 >= x && cnt1 != 0 &&
        cnt2 != 0) {
      cout << j;
      return 0;
    }
  }
  cout << 0;
}
