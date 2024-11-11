#include <bits/stdc++.h>
using namespace std;
int solve() {
  int n, s;
  cin >> n >> s;
  vector<pair<int, int> > v(n);
  for (long long int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  v.push_back({INT8_MAX, INT8_MAX});
  if (v[0].first * 60 + v[0].second > (s + 1)) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if ((v[i + 1].first * 60 + v[i + 1].second) -
            (v[i].first * 60 + v[i].second) >=
        (2 * s + 2)) {
      int min = v[i].first * 60 + v[i].second + s + 1;
      int hr = min / 60;
      min = min % 60;
      cout << hr << " " << min << endl;
      break;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  while (t--) solve();
  return 0;
}
