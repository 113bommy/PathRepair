#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e6;
int tt, n, m;
bool v[MAXN];
int a[MAXN];
int f[MAXN], t[MAXN];
vector<int> ans;
int main() {
  scanf("%d", &tt);
  while (tt--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 3; i++) {
      a[i] = -1;
      v[i] = 0;
    }
    ans.clear();
    for (int i = 1; i <= m; i++) {
      scanf("%d%d", &f[i], &t[i]);
    }
    int sum = 0;
    for (int i = 1; i <= m; i++) {
      int x = f[i], y = t[i];
      if (a[x] == -1 && a[y] == -1) {
        a[x] = 1;
        a[y] = 1;
        v[x] = 1;
        v[x] = 1;
        ans.push_back(i);
      }
    }
    bool judge = 1;
    if (ans.size() >= n) {
      judge = 0;
      puts("Matching");
      for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
      }
      printf("\n");
    } else {
      ans.clear();
      int now = 0;
      for (int i = 1; i <= 3 * n; i++) {
        if (!v[i]) {
          ans.push_back(i);
          now++;
          if (now >= n) {
            judge = 0;
            break;
          }
        }
      }
      if (!judge) {
        puts("IndSet");
        for (int i = 0; i < n; i++) {
          printf("%d ", ans[i]);
        }
        printf("\n");
      }
    }
    if (judge) {
      puts("Impossible");
    }
  }
  return 0;
}
