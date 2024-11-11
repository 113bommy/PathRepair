#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, ans[100005], t, i, j;
  cin >> n >> k;
  if (k == 0) {
    for (i = 1; i <= 2 * n; i++) ans[i] = i;
  } else {
    ans[1] = 1;
    ans[2] = 1 + k;
    t = 2 * n;
    i = 3;
    while (i <= 2 * n) {
      if (t != (1 + k) && t != 1) {
        ans[i] = t;
        t--;
        i = i + 2;
      } else
        t--;
    }
    j = 4;
    while (j <= 2 * n) {
      if (t != 1 + k && t != 1) {
        ans[j] = t;
        t--;
        j = j + 2;
      } else
        t--;
    }
  }
  for (i = 1; i <= 2 * n; i++) cout << ans[i] << " ";
  return 0;
}
