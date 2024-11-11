#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[300005];
vector<int> v[300005];
int cnt;
int main(int argc, char** argv) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    a[0] = {-1, 0};
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].second = i;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= cnt + 1; i++) v[i].clear();
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i].first != a[i - 1].first) ++cnt;
      v[cnt].push_back(a[i].second);
    }
    int lst = 1, now = 0, ans = 0;
    v[cnt + 1].push_back(-1);
    for (int i = 1; i <= cnt + 1; i++) {
      if (!v[i - 1].size() || v[i][0] > v[i - 1][v[i - 1].size() - 1])
        now += v[i].size();
      else {
        for (auto x : v[i])
          if (x > v[i - 1][v[i - 1].size() - 1]) ++now;
        for (auto x : v[lst - 1])
          if (x < v[lst][0]) ++now;
        ans = max(ans, now);
        lst = i, now = v[i].size();
      }
      int nw = 0;
      for (int j = 0; j < v[i].size(); j++) {
        while (nw < v[i + 1].size() && v[i + 1][nw] <= v[i][j]) ++nw;
        ans = max(ans, j + (int)v[i + 1].size() - nw);
      }
    }
    cout << n - ans << "\n";
  }
  return 0;
}
