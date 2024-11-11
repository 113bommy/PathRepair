#include <bits/stdc++.h>
using namespace std;
const pair<int, int> d[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int inf = 4e3 + 10;
int n, first;
int a[555];
int cnt = 1;
int ans = inf;
int main() {
  cin >> n >> first;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == first) cnt = 0;
  }
  if (cnt == 1) a[n + 1] = first;
  sort(a + 1, a + n + cnt + 1);
  for (int i = 1; i <= n + cnt; i++) {
    if (a[i] != first) continue;
    if (i < (n + 1 + cnt) / 2) {
      ans = min(ans, (n + cnt - i) - i);
    } else if (i == (n + 1 + cnt) / 2) {
      cout << cnt;
      return 0;
    } else {
      ans = min(ans, (i - 1) - (n + cnt - i));
    }
  }
  cout << ans + cnt;
}
