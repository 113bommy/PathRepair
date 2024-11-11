#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 23;
const int INF = 5e5 + 2;
int n, m;
int cnt[INF][23];
int main() {
  cin >> n >> m;
  int a1, a2;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a1, &a2);
    cnt[a1][0] = max(cnt[a1][0], a2);
  }
  for (int i = 1; i < INF; i++) cnt[i][0] = max(cnt[i][0], cnt[i - 1][0]);
  for (int i = 1; i < 21; i++) {
    for (int j = 0; j < INF; j++) {
      cnt[j][i] = cnt[cnt[j][i - 1]][i - 1];
    }
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    int ans = 0;
    for (int j = 20; j >= 0; j--) {
      if (j == 0) {
        if (cnt[l][0] == 0 || cnt[l][0] == l) continue;
        if (cnt[l][0] >= r) {
          l = r;
          ans++;
          break;
        } else {
          ans++;
          l = cnt[l][0];
          j++;
          continue;
        }
      }
      if (cnt[l][j] >= r || cnt[l][j] == 0) continue;
      if (cnt[l][j] == cnt[l][j - 1]) continue;
      ans += (1 << j);
      l = cnt[l][j];
      if (l == r) break;
    }
    if (l < r)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
}
