#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n;
pair<int, int> p[5];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x = 0, y = 0;
    cin >> x >> y;
    p[i] = make_pair(x, y);
  }
  if (n == 1) {
    printf("-1");
    return 0;
  }
  if (n == 2) {
    int ans = 0;
    if (p[0].first == p[1].first || p[0].second == p[1].second) {
      printf("-1");
      return 0;
    } else {
      ans = abs(p[0].first - p[1].first) * abs(p[0].second - p[1].second);
      cout << ans;
      return 0;
    }
  } else {
    int ans = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < n; j++) {
        if (p[i].first == p[j].first || p[i].second == p[j].second)
          continue;
        else {
          ans = abs(p[i].first - p[j].first) * abs(p[i].second - p[j].second);
          cout << ans;
          return 0;
        }
      }
    }
  }
}
