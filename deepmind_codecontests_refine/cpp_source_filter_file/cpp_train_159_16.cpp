#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5;
long long c, d;
int n, k, s, t, i, l, r, a[MN], b[MN], ans = 1 << 30;
pair<int, int> arr[MN];
int main() {
  for (scanf("%d%d%d%d", &n, &k, &s, &t), i = 1; i <= n; i++)
    scanf("%d%d", &arr[i].first, &arr[i].second);
  sort(arr + 1, arr + n + 1,
       [](pair<int, int> i, pair<int, int> j) { return i.second < j.second; });
  for (i = 1; i <= k; i++) scanf("%d", &b[i]);
  sort(b + 1, b + k + 1);
  for (i = 1; i <= k; i++) a[i] = b[i] - b[i - 1];
  a[k + 1] = s - b[k];
  k++;
  sort(a + 1, a + k + 1);
  for (i = l = r = 1; i <= n; i++) {
    while (r <= k && a[r] <= arr[i].second) {
      d += 3 * a[r++];
      c++;
    }
    while (l <= k && 2 * a[l] <= arr[i].second) {
      d -= 2 * a[l++];
      c--;
    }
    if (r == k + 1 && d - 1LL * arr[i].second * c <= t)
      ans = min(ans, arr[i].first);
  }
  printf("%d\n", ans == 1 << 30 ? -1 : ans);
  return 0;
}
