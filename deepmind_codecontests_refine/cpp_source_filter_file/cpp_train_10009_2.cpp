#include <bits/stdc++.h>
using namespace std;
struct road {
  long long mx;
  long long ar[1009];
};
road s[1009], e[1009];
long long n, m, a[1009][1009], ans[1009][1009], cur;
pair<long long, long long> t[1009];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) t[j] = {a[i][j], j};
    sort(t + 1, t + m + 1);
    cur = 1;
    e[i].ar[t[1].second] = 1;
    for (int j = 2; j <= m; j++) {
      if (t[j].first != t[j - 1].first) cur++;
      e[i].ar[t[j].second] = cur;
    }
    e[i].mx = cur;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) t[j] = {a[i][j], j};
    sort(t + 1, t + n + 1);
    cur = 1;
    s[i].ar[t[1].second] = 1;
    for (int j = 2; j <= n; j++) {
      if (t[j].first != t[j - 1].first) cur++;
      s[i].ar[t[j].second] = cur;
    }
    s[i].mx = cur;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      ans[i][j] = max(e[i].ar[j], s[j].ar[i]) +
                  max(e[i].mx - e[i].ar[j], s[j].mx - s[j].ar[i]);
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << ans[i][j] << ' ';
    cout << endl;
  }
}
