#include <bits/stdc++.h>
using namespace std;
const int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dc[] = {0, -1, 0, 1, -1, 1, -1, 1};
const int N = 112345;
const int M = 1123456;
int n, a[N];
vector<int> ans;
bool app[M], day[M];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int last = 0, cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > 0) {
      if (day[a[i]]) {
        cout << -1 << '\n';
        return false;
      }
      app[a[i]] = day[a[i]] = true;
      ++cnt;
    } else {
      if (!app[-a[i]]) {
        cout << -1 << '\n';
        return 0;
      }
      app[-a[i]] = false;
      --cnt;
      if (cnt == 0) {
        ans.push_back(i - last);
        for (int j = last + 1; j <= i; ++j)
          app[abs(a[j])] = day[abs(a[j])] = false;
        last = i;
      }
    }
  }
  if (cnt > 0)
    cout << -1 << '\n';
  else {
    cout << ans.size() << '\n';
    for (auto it : ans) cout << it << ' ';
    cout << '\n';
  }
  return 0;
}
