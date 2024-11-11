#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n, k, a[maxn], num;
bool ex[maxn], need[maxn];
int main() {
  scanf("%d%d", &n, &k);
  num = 0;
  memset(ex, 0, sizeof(ex));
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (ex[a[i]]) continue;
    if (num < k) {
      num++;
      ans++;
      ex[a[i]] = true;
    } else {
      int sum = 0;
      memset(need, 0, sizeof(need));
      for (int j = i + 1; j < n && sum < k - 1; j++) {
        if (!ex[a[j]]) continue;
        if (need[a[j]] == false) sum++;
        need[a[j]] = true;
      }
      for (int j = 1; j <= n; j++) {
        if (ex[j] && (!need[j])) {
          ex[j] = false;
          ex[a[i]] = true;
          ans++;
          break;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
