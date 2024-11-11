#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < (n); i++) cin >> a[i].first >> a[i].second;
  sort(a.begin(), a.end());
  int l, r, p = n;
  l = r = 0;
  for (int i = 0; i < (n); i++) {
    if (a[i].first < 0) {
      l++;
    } else {
      if (!r) p = i;
      r++;
    }
  }
  int d = min(l, r);
  int off = l < r ? 1 : 0;
  int cnt = 0;
  for (int i = 0; i < d + off; i++) {
    cnt += a[i + p].second;
  }
  off = l > r ? 1 : 0;
  for (int i = 0; i < d + off; i++) {
    cnt += a[p - i - 1].second;
  }
  cout << cnt << endl;
  return 0;
}
