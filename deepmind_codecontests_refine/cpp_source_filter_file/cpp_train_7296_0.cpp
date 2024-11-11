#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  bool flag[35];
  for (int i = 0; i < n; i++) {
    cout << 1 << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    if (ans == 0) return 0;
    flag[i] = ans == 1;
  }
  int p = 1, q = m + 1, now = 0;
  while (q > p) {
    int mid = (p + q) >> 1;
    cout << mid << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    if (!flag[now++]) ans = -ans;
    now %= n;
    if (ans == 0) return 0;
    if (ans == -1)
      p = mid + 1;
    else
      q = mid;
  }
  return 0;
}
