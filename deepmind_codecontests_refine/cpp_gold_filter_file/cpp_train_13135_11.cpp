#include <bits/stdc++.h>
using namespace std;
int n;
const int mbit = 21;
const int mval = (1 << mbit);
pair<int, int> dp[(1 << mbit)];
int a[1000010], rez;
void mrg(pair<int, int> &x, pair<int, int> y) {
  pair<int, int> ret = {0, 0};
  if (x.first > y.first) {
    ret.first = x.first;
    ret.second = max(x.second, y.first);
  } else {
    ret.first = y.first;
    ret.second = max(y.second, x.first);
  }
  x = ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    mrg(dp[a[i]], {i, 0});
  }
  for (int i = 0; i < mbit; i++)
    for (int j = 0; j < mval; j++)
      if (!(j & (1 << i))) mrg(dp[j], dp[j ^ (1 << i)]);
  for (int i = 1; i <= n; i++) {
    int mask = a[i];
    int w = 0;
    for (int j = mbit - 1; j >= 0; j--) {
      if (mask & (1 << j)) continue;
      if (dp[w | (1 << j)].first > i && dp[w | (1 << j)].second > i)
        w |= (1 << j);
    }
    if (w == 0) {
      if (dp[0].first > i && dp[0].second > i)
        rez = max(rez, (mask | w));
      else
        continue;
    } else
      rez = max(rez, (mask | w));
  }
  printf("%d\n", rez);
  return 0;
}
