#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5005, MAXC = 1000005;
int a[MAXN], b[MAXC], c[MAXC];
int n, k, _max;
int main() {
  if (0) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  };
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), _max = max(_max, a[i]);
  for (int i = 1; i < n; i++)
    for (int j = i + 1; j <= n; j++) b[abs(a[i] - a[j])]++;
  for (int res = n - k; res <= 1000001; res++) {
    int cnt = 0;
    bool ok = true;
    for (int i = res; i <= _max; i += res) {
      cnt += b[i];
      if (cnt > (k + 1) * k / 2) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    int x = 0;
    for (int i = 1; i <= n; i++) {
      if (c[a[i] % res]) x++;
      c[a[i] % res]++;
    }
    if (x <= k + 1) {
      cout << res << endl;
      return 0;
    }
    for (int i = 1; i <= n; i++) c[a[i] % res] = 0;
  }
  return 0;
}
