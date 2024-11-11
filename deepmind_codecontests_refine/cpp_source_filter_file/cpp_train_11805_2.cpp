#include <bits/stdc++.h>
using namespace std;
int a[100000], b[100000];
vector<pair<int, int> > ca, cb;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0, _n = n; i < _n; i++) cin >> a[i];
  for (int i = 0, _n = m; i < _n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (i < n - 1) {
      if (a[i + 1] != a[i]) {
        ca.push_back(make_pair(a[i + 1], cnt));
        cnt = 1;
      } else
        cnt++;
    } else
      cnt++;
  }
  ca.push_back(make_pair(a[0], cnt));
  cnt = 0;
  for (int i = m - 1; i >= 0; i--) {
    if (i < m - 1) {
      if (b[i + 1] != b[i]) {
        cb.push_back(make_pair(b[i + 1], cnt));
        cnt = 1;
      } else
        cnt++;
    } else
      cnt++;
  }
  cb.push_back(make_pair(b[0], cnt));
  int ka = 0, kb = 0, l = 0, r = 0;
  while (true) {
    if (r == cb.size()) {
      while (l < ca.size()) {
        ka += ca[l].second;
        l++;
      }
      break;
    }
    if (l == ca.size()) break;
    if (ca[l].first > cb[r].first) {
      ka += ca[l].second;
      l++;
    } else if (cb[r].first > ca[l].first) {
      kb += cb[r].second;
      r++;
    } else if (ca[l].first == cb[r].first) {
      ka += ca[l].second;
      kb += cb[r].second;
      l++;
      r++;
    }
    if (ka > kb) {
      cout << "YES\n";
      return 0;
    }
  }
  if (ka > kb) {
    cout << "YES\n";
  } else
    cout << "NO\n";
  return 0;
}
