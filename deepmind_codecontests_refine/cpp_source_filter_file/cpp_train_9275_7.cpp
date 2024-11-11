#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, l, r, f = 0;
  cin >> n;
  int a[n + 1];
  char s[n + 1], ss[n + 1];
  vector<pair<int, int> > v;
  v.push_back(make_pair(-1, -1));
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    v.push_back(make_pair(a[i], i));
  }
  sort(v.begin(), v.end());
  for (i = n; i >= 1; i--) {
    f = 0;
    l = v[i].first;
    r = v[i].second;
    while (r <= n) {
      r += l;
      if (r <= n)
        if (a[r] > v[i].first) {
          if (s[i] != 'A') {
            f = 1;
            s[i] = s[r] == 'B' ? 'A' : 'B';
            if (s[i] == 'A') break;
          }
        }
    }
    l = v[i].first;
    r = v[i].second;
    while (r >= 1) {
      r -= l;
      if (r >= 1)
        if (a[r] > v[i].first) {
          if (s[i] != 'A') {
            f = 1;
            s[i] = s[r] == 'B' ? 'A' : 'B';
            if (s[i] == 'A') break;
          }
        }
    }
    s[i] = f == 0 ? 'B' : s[i];
  }
  for (i = 1; i <= n; i++) {
    ss[v[i].second] = s[i];
  }
  for (i = 1; i <= n; i++) cout << ss[i];
}
