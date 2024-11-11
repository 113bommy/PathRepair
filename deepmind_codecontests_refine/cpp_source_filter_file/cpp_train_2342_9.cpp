#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  while (cin >> n) {
    vector<pair<long long, long long> > a(n);
    for (int i = 0; i < n; i++) a[i].second = i, cin >> a[i].first;
    sort(a.begin(), a.end());
    vector<pair<long long, long long> > res(n, {1e9, 1e9});
    for (int i = 0; i < n; i++) {
      res[a[i].second].second =
          max(abs(a[i].first - a[0].first), abs(a[i].first - a[n - 1].first));
      if (i)
        res[a[i].second].first =
            min(res[a[i].second].first, abs(a[i].first - a[i - 1].first));
      if (i + 1 < n)
        res[a[i].second].first =
            min(res[a[i].second].first, abs(a[i].first - a[i + 1].first));
    }
    for (int i = 0; i < n; i++)
      cout << res[i].first << ' ' << res[i].second << endl;
  }
  return 0;
}
