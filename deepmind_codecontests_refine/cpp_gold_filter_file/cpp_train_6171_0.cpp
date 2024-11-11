#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n;
int arr1[10];
int arr2[100005];
pair<int, int> diffs[600005];
int cnts[100005];
int main() {
  while (scanf("%d", arr1) == 1) {
    for (int i = 1; i < 6; ++i) {
      scanf("%d", arr1 + i);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr2 + i);
    }
    int idx = 0;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < n; ++j) {
        diffs[idx].first = arr2[j] - arr1[i];
        diffs[idx].second = j;
        ++idx;
      }
    }
    sort(diffs, diffs + idx);
    memset(cnts, 0, sizeof(cnts));
    int cnt = 0;
    int j = 0;
    int ans = INF;
    for (int i = 0; i < 5 * n; ++i) {
      if (i && --cnts[diffs[i - 1].second] <= 0) {
        --cnt;
      }
      while (cnt < n && j < 6 * n) {
        if (cnts[diffs[j].second]++ == 0) {
          ++cnt;
        }
        ++j;
      }
      if (cnt >= n) {
        ans = min(ans, diffs[j - 1].first - diffs[i].first);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
