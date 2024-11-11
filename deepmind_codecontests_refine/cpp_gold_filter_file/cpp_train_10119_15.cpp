#include <bits/stdc++.h>
using namespace std;
const int ST[10] = {1,      10,      100,      1000,      10000,
                    100000, 1000000, 10000000, 100000000, 1000000000};
int a[10][10], i, j, n, k, x, ch[10], z, ans, met, maxx, minn;
int cs[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int main() {
  cin >> n >> k;
  for (i = 0; i < n; ++i) {
    cin >> x;
    for (j = 0; j < k; ++j) {
      a[i][k - j - 1] = x % 10;
      x = x / 10;
    }
    ch[i] = 0;
  }
  x = true;
  ans = 1000000000;
  while (x) {
    x = next_permutation(cs, cs + k);
    for (i = 0; i < n; ++i) ch[i] = 0;
    for (i = 0; i < n; ++i) {
      for (j = 0; j < k; ++j) {
        ch[i] = ch[i] + (a[i][cs[j]] * ST[k - j - 1]);
      }
    }
    minn = 1000000000;
    maxx = -1;
    for (i = 0; i < n; ++i) {
      if (ch[i] > maxx) maxx = ch[i];
      if (ch[i] < minn) minn = ch[i];
    }
    met = maxx - minn;
    if (met < ans) ans = met;
  }
  cout << ans;
  return 0;
}
