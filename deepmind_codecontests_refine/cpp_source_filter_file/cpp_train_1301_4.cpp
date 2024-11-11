#include <bits/stdc++.h>
using namespace std;
long long a[1234567];
std::vector<pair<int, int> > v;
int main() {
  int n, k, pos, i;
  cin >> n >> k;
  long long s = 0, r;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    r = (a[i]) % 10;
    if (r >= 5) r = 10 - r;
    v.push_back(make_pair(r, i));
    s += r;
  }
  sort(v.begin(), v.end());
  if (k >= s) {
    for (i = 0; i < n; i++) {
      r = (a[i]) % 10;
      if (r >= 5) r = 10 - r;
      a[i] = a[i] + r;
      k = k - r;
    }
  } else {
    for (int i = 0; i < (int)v.size(); i++) {
      if (k >= v[i].first) {
        pos = v[i].second;
        a[pos] = a[pos] + v[i].first;
        k -= v[i].first;
      }
    }
  }
  for (i = 0; i < n; i++) {
    while ((a[i] + 10) <= 100 && k >= 10) {
      a[i] = a[i] + 10;
      k -= 10;
    }
  }
  long long ans = 0;
  for (i = 0; i < n; i++) {
    ans = ans + a[i] / 10;
  }
  cout << ans << endl;
  return 0;
}
