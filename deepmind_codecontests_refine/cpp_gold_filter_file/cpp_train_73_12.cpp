#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
bool can[MAXN];
int val[MAXN], lx = 0, tmp = 0, pre = 0, precan[MAXN], n, m, k;
int main() {
  memset(can, 1, sizeof(can));
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    int tmp;
    scanf("%d", &tmp);
    can[tmp] = 0;
  }
  if (!can[0]) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", &val[i]);
  }
  for (int i = 0; i < n; i++) {
    if (can[i])
      tmp = 0, pre = i;
    else
      tmp++, lx = max(lx, tmp), precan[i] = pre;
  }
  long long tmpans = 0, ans = (1ll << 55);
  for (int l = lx + 1; l <= k; l++) {
    tmpans = 0;
    for (int j = 0; j < n; j += (l)) {
      if (!can[j]) j = precan[j];
      tmpans += val[l];
    }
    if (tmpans != 0) ans = min(ans, tmpans);
  }
  if (ans != (1ll << 55))
    cout << ans << endl;
  else
    puts("-1");
  return 0;
}
