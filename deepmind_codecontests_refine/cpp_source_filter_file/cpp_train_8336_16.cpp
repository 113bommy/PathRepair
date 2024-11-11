#include <bits/stdc++.h>
using namespace std;
const long long upper = 1ll << 17;
const int N = 120005;
bool vis[N];
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n + 5);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  if (n == 0) {
    printf("0\n");
    return 0;
  }
  sort(a.begin(), a.begin() + n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i && a[i] == a[i - 1]) {
      vis[i] = vis[i - 1];
      if (vis[i] == false) ans++;
      continue;
    }
    for (int j = 1; j < 18; j++) {
      int t =
          lower_bound(a.begin(), a.begin() + n, (1ll << j) - a[i]) - a.begin();
      if (t == i) t++;
      if (t < n && a[t] + a[i] == (1ll << j)) {
        vis[i] = true;
        break;
      }
    }
    if (!vis[i]) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
