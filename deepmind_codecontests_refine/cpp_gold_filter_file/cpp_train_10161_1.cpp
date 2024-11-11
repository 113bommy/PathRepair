#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double pi = 3.141592653589793238462;
const int nmax = 2000;
const int hash_base = 119;
const long long inf = 2e9;
int n, m, ans[nmax];
pair<int, int> val[nmax], val1[nmax];
bool check() {
  for (int i = 1; i < n; i++)
    if (ans[i] == ans[i + 1] || ans[i] == 0) return false;
  return ans[1] != ans[n] && ans[n];
};
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &val[i].first);
    val[i].second = i;
    val1[i] = val[i];
  };
  sort(val + 1, val + m + 1);
  ans[1] = val[1].second;
  val[1].first--;
  for (int i = 2; i <= n; i++) {
    for (int j = m; j >= 1; j--)
      if (val[j].first != 0 && ans[i - 1] != val[j].second) {
        if (i == n && ans[1] == val[j].second) {
          ans[n] = ans[n - 1];
          ans[n - 1] = val[j].second;
          continue;
        };
        ans[i] = val[j].second;
        --val[j].first;
        break;
      };
  };
  if (!check()) {
    for (int q = 1; q <= m; q++) val[q] = val1[q];
    sort(val + 1, val + m + 1);
    ans[1] = val[m].second;
    --val[m].first;
    for (int i = 2; i <= n; i++) {
      for (int j = m; j >= 1; j--)
        if (val[j].first != 0 && ans[i - 1] != val[j].second) {
          if (i == n && ans[1] == val[j].second) {
            ans[n] = ans[n - 1];
            ans[n - 1] = val[j].second;
            continue;
          };
          ans[i] = val[j].second;
          --val[j].first;
          break;
        };
    };
    if (!check()) {
      memset(ans, 0, sizeof(ans));
      int it = 1;
      while (it <= n) {
        bool has = false;
        for (int i = 1; i <= m && it <= n; i++)
          if (val1[i].first != 0) {
            ans[it++] = val1[i].second;
            --val1[i].first;
            has = true;
          };
        if (!has) break;
      };
      if (ans[1] == ans[n]) swap(ans[1], ans[2]);
      if (!check()) {
        swap(ans[1], ans[2]);
        swap(ans[n], ans[n - 1]);
        if (!check())
          printf("-1\n");
        else {
          for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        };
      } else {
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
      };
    } else {
      for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    };
  } else {
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  }
  return 0;
}
