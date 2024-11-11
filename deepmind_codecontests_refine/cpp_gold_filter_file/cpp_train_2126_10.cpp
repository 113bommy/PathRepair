#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int n;
int a[N];
bool can[N];
pair<int, int> from[N];
vector<pair<int, int> > f;
inline bool modify() {
  if (a[1] > 1 || a[2] > 1) return false;
  int mx = 0;
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      if (a[i] < mx) return false;
      mx = max(mx, a[i]);
    }
  int idx = 1, val = 1;
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      if (a[i] == val) {
        for (int j = idx; j < i; j++) a[j] = val;
      } else {
        val = a[i];
        idx = i;
      }
    }
  f.push_back(pair<int, int>(0, 0));
  int i = 1;
  while (i <= n) {
    if (a[i]) {
      int cnt = 1;
      while (i < n && a[i] == a[i + 1]) i++, cnt++;
      if (cnt > 5) return false;
      f.push_back(pair<int, int>(i - cnt + 1, i));
    }
    i++;
  }
  f.push_back(pair<int, int>(n + 1, n + 1));
  return true;
}
inline void gensol(int i, int x) {
  if (i == 0) return;
  int j = i;
  for (int k = 0; k < from[i].second; j--, k++) a[j] = a[f[x].first];
  int next = from[i].first;
  int len = j - next;
  int dif = a[f[x].first] - a[f[x - 1].first] - 1;
  if (dif > 0) {
    int q = len / dif;
    int r = len % dif;
    for (int z = 0; z < dif; z++) {
      if (z < r) a[++next] = z + a[f[x - 1].first] + 1;
      for (int k = 0; k < q; k++) {
        a[++next] = z + a[f[x - 1].first] + 1;
      }
    }
  }
  gensol(from[i].first, x - 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  if (!modify()) {
    printf("-1\n");
    return 0;
  }
  can[0] = true;
  for (int i = 1; i < f.size() - 1; i++) {
    int cnt = f[i].second - f[i].first + 1;
    for (int j = f[i - 1].second; j < f[i].first; j++)
      if (can[j]) {
        int dif = a[f[i].first] - a[f[i - 1].first] - 1;
        int l = 2 * dif + j;
        int r = 5 * dif + j;
        for (int x = max(2, cnt); x <= 5; x++)
          for (int y = 0; y <= x - cnt; y++) {
            int z = f[i].first - y - 1;
            if (l <= z && z <= r && z + x < f[i + 1].first) {
              can[z + x] = true;
              from[z + x] = pair<int, int>(j, x);
            }
          }
      }
  }
  for (int i = f[f.size() - 2].second; i <= n; i++)
    if (can[i]) {
      int len = n - i;
      if (len == 1) continue;
      int ans = a[f[f.size() - 2].first];
      if (len & 1) {
        a[i + 1] = ans + 1;
        for (int j = i + 2; j <= n; j += 2) ans++, a[j] = ans, a[j + 1] = ans;
      } else {
        for (int j = i + 1; j <= n; j += 2) ans++, a[j] = ans, a[j + 1] = ans;
      }
      printf("%d\n", ans);
      gensol(i, f.size() - 2);
      for (int i = 1; i <= n; i++) printf("%d ", a[i]);
      return 0;
    }
  printf("-1\n");
}
