#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    ;
    long long int k;
    cin >> k;
    ;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    ;
    vector<int> v, r;
    for (int i = 0; i < n; i++) {
      if (a[i] > 0)
        v.push_back(a[i]);
      else
        r.push_back(abs(a[i]));
    }
    sort(v.begin(), v.end());
    sort(r.begin(), r.end());
    int w = v.size(), y = r.size();
    long long int ans = 0;
    int i = w - 1, i1 = y - 1;
    while (1) {
      if (i < 0) break;
      if (i == w - 1 && (y > 0 && w > 0 && v[w - 1] > r[y - 1]))
        ans += v[i];
      else if (i == w - 1 && y == 0)
        ans += v[i];
      else
        ans += 2 * v[i];
      i = i - k;
      if (i < 0) break;
    }
    while (1) {
      if (i1 < 0) break;
      if (i1 == y - 1 && (y > 0 && w > 0 && v[w - 1] <= r[y - 1]))
        ans += r[i1];
      else if (i1 == y - 1 && w == 0)
        ans += r[i1];
      else
        ans += 2 * r[i1];
      i1 = i1 - k;
      if (i1 < 0) break;
    }
    cout << ans << endl;
  }
}
