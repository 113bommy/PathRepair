#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int n, m, k;
int s[MX], a[MX];
int b[MX];
int main() {
  while (cin >> n >> m >> k) {
    for (int i = 1; i <= m; i++) scanf("%d", &s[i]), b[s[i]] = 1;
    for (int i = 1; i <= k; i++) scanf("%d", &a[i]);
    m = 0;
    for (int i = 0; i <= n; i++)
      if (!b[i]) s[++m] = i;
    if (s[1] > 0) {
      printf("-1\n");
      continue;
    }
    int kk = 0;
    for (int i = 1; i <= k; i++) {
      while (kk > 0 && a[i] <= a[kk]) kk--;
      a[++kk] = a[i];
      b[kk] = i;
    }
    k = kk;
    long long ans = INF;
    for (int i = 1; i <= k; i++) {
      int x = b[i], cnt = 0;
      int index = 1, flag = 1;
      while (index <= m) {
        if (s[index] + x >= n) {
          cnt++;
          break;
        }
        int p = upper_bound(s + 1, s + m + 1, s[index] + x) - s - 1;
        cnt++;
        if (p == index) {
          flag = 0;
          break;
        }
        index = p;
      }
      if (flag) ans = min(ans, (long long)cnt * a[i]);
    }
    cout << (ans == INF ? -1 : ans) << endl;
  }
  return 0;
}
