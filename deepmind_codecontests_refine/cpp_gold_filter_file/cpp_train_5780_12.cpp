#include <bits/stdc++.h>
using namespace std;
int n, m, pos[123456];
pair<pair<int, int>, int> way[123456];
pair<int, int> ans[123456];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  int w, yon;
  for (int i = 1; i <= m; i++) {
    cin >> w >> yon;
    way[i] = make_pair(make_pair(w, 1 - yon), i);
  }
  sort(way + 1, way + m + 1);
  int cnt = 1, now = 2;
  for (int i = 1; i <= n; i++) pos[i] = i;
  for (int i = 1; i <= m; i++) {
    if (!way[i].first.second) {
      cnt++;
      ans[way[i].second] = make_pair(1, cnt);
      now = 2;
      if (cnt > n) {
        cout << -1;
        return 0;
      }
    } else {
      while (now <= cnt && pos[now] >= cnt) now++;
      if (now > cnt) {
        cout << -1;
        return 0;
      }
      ans[way[i].second] = make_pair(now, ++pos[now]);
    }
  }
  for (int i = 1; i <= m; i++)
    cout << ans[i].first << " " << ans[i].second << "\n";
  return 0;
}
