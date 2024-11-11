#include <bits/stdc++.h>
using namespace std;
const int MAXX = 2e2 + 10;
int n, ans;
pair<int, int> a[MAXX];
bool ok(int c, int i, int x) {
  if (c == 1) return (a[i].first > a[x].first && a[i].second == a[x].second);
  if (c == 2) return (a[i].first < a[x].first && a[i].second == a[x].second);
  if (c == 3) return (a[i].first == a[x].first && a[i].second < a[x].second);
  if (c == 4) return (a[i].first == a[x].first && a[i].second > a[x].second);
}
bool Linear_Search(int x) {
  bool flag[5] = {0, 0, 0, 0, 0};
  for (int cnt = 1; cnt <= 4; cnt++)
    for (int i = 0; i < n; i++)
      if (ok(cnt, i, x)) flag[cnt] = 1;
  for (int i = 1; i <= 4; i++)
    if (flag[i] == 0) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  for (int i = 0; i < n; i++)
    if (Linear_Search(i)) ans++;
  return cout << ans << endl, 0;
}
