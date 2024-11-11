#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const long long inf = 1e18;
int t, n;
int a[maxn], ans[maxn];
vector<int> p[maxn];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      p[i].clear();
      p[i].push_back(0);
      ans[i] = -1;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      p[a[i]].push_back(i);
    }
    if (n == 1) {
      printf("%d\n", a[1]);
      continue;
    }
    for (int i = 1; i <= n; i++) {
      p[i].push_back(n + 1);
      int mi = 0;
      int sz = p[i].size();
      for (int j = 1; j < sz; j++) mi = max(mi, p[i][j] - p[i][j - 1]);
      if (mi > 0) {
        if (ans[mi] == -1) ans[mi] = i;
      }
    }
    printf("%d ", ans[1]);
    for (int i = 2; i <= n; i++)
      if (ans[i] == -1) {
        ans[i] = ans[i - 1];
      } else if (ans[i - 1] != -1)
        ans[i] = min(ans[i], ans[i - 1]);
    for (int i = 2; i <= n; i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
