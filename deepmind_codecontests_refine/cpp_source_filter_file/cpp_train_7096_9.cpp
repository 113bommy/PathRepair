#include <bits/stdc++.h>
using namespace std;
int n, m;
int b[1005];
int c[1005];
int d[1005];
int l[1005];
int r[1005];
pair<pair<int, int>, int> a[1005];
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  int i, j;
  for (i = 1; i <= m; i++) {
    int t, l, r;
    cin >> a[i].second >> a[i].first.first >> a[i].first.second;
  }
  sort(a + 1, a + m + 1);
  for (i = 1; i <= m; i++) {
    int t = a[i].second;
    l[i] = a[i].first.first;
    r[i] = a[i].first.second;
    if (t == 1) {
      for (j = l[i] - 1; j >= 1; j--) {
        if (b[j] >= l[i]) b[j] = max(b[j], r[i]);
      }
      for (j = r[i]; j >= l[i]; j--) {
        b[j] = max(b[j], r[i]);
      }
    }
    if (t == 0) {
      for (j = l[i]; j >= 1; j--) {
        if (c[j] == 0)
          c[j] = r[i];
        else
          c[j] = min(c[j], r[i]);
      }
    }
  }
  for (i = 1; i <= n; i++) {
    if (c[i] != 0 && c[i] <= b[i]) {
      cout << "NO";
      return 0;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= b[i]; j++) {
      d[j] = 1;
    }
  }
  int cnt = 0;
  for (i = 1; i <= n; i++) {
    for (j = i + 1; j <= c[i]; j++) {
      if (d[j] == 0) {
        d[j] = --cnt;
      }
    }
  }
  for (i = 1; i <= n; i++) d[i] -= cnt;
  cout << "YES\n";
  for (i = 1; i <= n; i++) cout << d[i] << " ";
  return 0;
}
