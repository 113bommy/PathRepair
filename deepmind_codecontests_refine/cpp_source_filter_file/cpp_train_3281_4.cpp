#include <bits/stdc++.h>
using namespace std;
int n, m;
int f[50005];
int g[1000005];
int a[50005];
struct wen {
  int l, r, i;
} w[50005];
int ans[50005];
int cnt;
bool cmp(wen a, wen b) { return (a.r - a.l < b.r - b.l); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &w[i].l, &w[i].r);
    w[i].i = i;
  }
  sort(w + 1, w + m + 1, cmp);
  cnt = 1;
  for (int i = 1; i <= n; i++) g[i] = g[i - 1] ^ i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j + i - 1 <= n; j++) {
      f[j] = ((((f[j]) > (f[j + 1]) ? (f[j]) : (f[j + 1]))) >
                      ((a[j] > a[i + j - 1] ? g[a[j]] ^ g[a[i + j - 1] - 1]
                                            : g[a[i + j - 1]] ^ g[a[j] - 1]))
                  ? (((f[j]) > (f[j + 1]) ? (f[j]) : (f[j + 1])))
                  : ((a[j] > a[i + j - 1] ? g[a[j]] ^ g[a[i + j - 1] - 1]
                                          : g[a[i + j - 1]] ^ g[a[j] - 1])));
    }
    while (w[cnt].r - w[cnt].l + 1 == i && cnt <= m) {
      ans[w[cnt].i] = f[w[cnt].l];
      cnt++;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}
