#include <bits/stdc++.h>
using namespace std;
int arr[1010][1010];
vector<int> sx[1010], sy[1010];
int main() {
  int n, i, j, k, x, y, ans, curr, temp, pjg, tc, m, r, c, rose = 0, low, high;
  scanf("%d %d", &r, &c);
  for (i = 1; i <= r; i++)
    for (j = 1; j <= c; j++) scanf("%d", &arr[i][j]);
  for (i = 1; i <= r; i++) {
    map<int, int> mp;
    for (j = 1; j <= c; j++) {
      if (mp[arr[i][j]] == 0) sx[i].push_back(arr[i][j]);
      mp[arr[i][j]] = 1;
    }
  }
  for (i = 1; i <= c; i++) {
    map<int, int> mp;
    for (j = 1; j <= r; j++) {
      if (mp[arr[i][j]] == 0) sy[i].push_back(arr[j][i]);
      mp[arr[i][j]] = 1;
    }
  }
  for (i = 1; i <= r; i++) sort(sx[i].begin(), sx[i].end());
  for (i = 1; i <= c; i++) sort(sy[i].begin(), sy[i].end());
  for (i = 1; i <= r; i++) {
    for (j = 1; j <= c; j++) {
      low = high = 0;
      low = max(low, (int)(lower_bound(sx[i].begin(), sx[i].end(), arr[i][j]) -
                           sx[i].begin()));
      low = max(low, (int)(lower_bound(sy[j].begin(), sy[j].end(), arr[i][j]) -
                           sy[j].begin()));
      high =
          max(high, (int)(sx[i].size() -
                          (upper_bound(sx[i].begin(), sx[i].end(), arr[i][j]) -
                           sx[i].begin())));
      high =
          max(high, (int)(sy[j].size() -
                          (upper_bound(sy[j].begin(), sy[j].end(), arr[i][j]) -
                           sy[j].begin())));
      rose = low + high + 1;
      printf("%d ", rose);
    }
    printf("\n");
  }
  return 0;
}
