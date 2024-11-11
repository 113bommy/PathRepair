#include <bits/stdc++.h>
using namespace std;
int a[100000];
pair<int, int> r[110000];
int main() {
  ios_base::sync_with_stdio(0);
  int n, ans = 1;
  cin >> n;
  if (n < 3) {
    cout << n << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int j = i, cnt = 1;
    while (j < n && a[j] < a[j + 1]) j++, cnt++;
    int t = cnt;
    for (int z = i; z <= j; z++) {
      r[z].first = cnt;
      r[z].second = t - cnt + 1;
      cnt--;
    }
    i = j;
  }
  a[n + 1] = 1000000010;
  r[n + 1].first = 0;
  a[0] = -1000000010;
  r[0].second = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, r[i].second + 1);
    if (a[i - 1] + 1 < a[i + 1]) {
      ans = max(ans, r[i + 1].first + r[i - 1].second + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
