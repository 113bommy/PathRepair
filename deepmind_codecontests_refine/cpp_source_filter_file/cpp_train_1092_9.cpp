#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() {
  int n, m, i, j, k, l, f = 0, ct = 0, ans = 0, ll;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  l = 0;
  while (l < m) {
    vector<int> v(a, a + n);
    for (j = 0; j < l; j++) {
      for (i = 0; i < n; i++) v.push_back(a[i]);
    }
    multiset<int> s;
    for (i = 0; i < v.size(); i++) {
      s.insert(v[i]);
      if (s.upper_bound(v[i]) != s.end()) {
        s.erase(s.upper_bound(v[i]));
      }
    }
    if (v.size() == n)
      k = s.size();
    else {
      if (f == 0) {
        ll = s.size() - k;
        f = 1;
      } else {
        j = s.size() - k;
        if (j == ll)
          ct++;
        else {
          ct = 0;
          ll = j;
        }
      }
      k = s.size();
    }
    l++;
    ans = s.size();
    if (ct > 30) {
      ans = s.size() + (m - l) * ll;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
