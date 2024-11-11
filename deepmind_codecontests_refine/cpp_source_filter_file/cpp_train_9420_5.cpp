#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
pair<int, int> a[MAXN];
int cnt[MAXN];
int main() {
  int n;
  cin >> n;
  int tot = 0;
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) {
    cin >> a[i].second;
    tot += a[i].second;
  }
  sort(a, a + n);
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (a[i].first == a[j].first) {
      tot -= a[j].second;
      j++;
    }
    int c = j - i;
    int s = tot;
    int need = min(0, j - (2 * c - 1));
    for (int k = 1; k <= 200; k++) {
      s += min(need, cnt[k]) * k;
      need -= min(need, cnt[k]);
    }
    for (int k = i; k < j; k++) cnt[a[k].second]++;
    i = j - 1;
    ans = min(ans, s);
  }
  cout << ans << endl;
  return 0;
}
