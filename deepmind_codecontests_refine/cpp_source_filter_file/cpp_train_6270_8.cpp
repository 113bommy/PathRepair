#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000;
const int MAXL = 19;
int a[MAXN + 5], b[MAXN + 5], res[MAXN + 5];
int Min[MAXN + 5][MAXL + 5], Max[MAXN + 5][MAXL + 5];
pair<int, int> get(int left, int right) {
  int len = right - left + 1;
  int bin = b[len];
  return make_pair(min(Min[left][bin], Min[right - (1 << bin)][bin]),
                   max(Max[left][bin], Max[right - (1 << bin)][bin]));
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  b[1] = 0;
  for (int i = 2; i <= n; ++i) {
    b[i] = b[i - 1];
    if ((i & (-i)) == i) b[i]++;
  }
  a[0] = a[1];
  a[n + 1] = a[n];
  for (int i = 0; i <= n; ++i) {
    Min[i][0] = max(a[i], a[i + 1]);
    Max[i][0] = min(a[i], a[i + 1]);
  }
  for (int i = 1; i < MAXL; ++i) {
    for (int j = 0; j <= n - (1 << (i - 1)); ++j) {
      Min[j][i] = min(Min[j][i - 1], Min[j + (1 << (i - 1))][i - 1]);
      Max[j][i] = max(Max[j][i - 1], Max[j + (1 << (i - 1))][i - 1]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int left = 1, right = min(i, n + 1 - i), d = 0;
    while (left <= right) {
      int mid = (left + right) / 2;
      auto tmp = get(i - mid, i + mid);
      if (tmp.first <= tmp.second) {
        d = mid;
        right = mid - 1;
      } else
        left = mid + 1;
    }
    if (d == 1)
      res[i] = a[i];
    else {
      auto tmp = get(i - d, i + d);
      if (a[i] > a[i - 1]) {
        if (d % 2 == 0)
          res[i] = tmp.second;
        else
          res[i] = tmp.first;
      } else {
        if (d % 2 == 1)
          res[i] = tmp.second;
        else
          res[i] = tmp.first;
      }
    }
    ans = max(ans, d - 1);
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; ++i) cout << res[i] << " ";
  cout << '\n';
  return 0;
}
