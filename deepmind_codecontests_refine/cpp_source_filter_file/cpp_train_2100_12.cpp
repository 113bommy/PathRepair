#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long ar[n];
  long long cum[m];
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  vector<pair<long long, long long> > v(m);
  vector<long long> v1;
  for (int i = 0; i < m; i++) {
    cin >> v[i].first >> v[i].second;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < m; i++) {
    cum[i] = v[i].second;
    v1.push_back(v[i].first);
  }
  for (int i = 1; i < m; i++) {
    cum[i] += cum[i - 1];
  }
  for (int i = 0; i < n; i++) {
    long long cnt;
    long long l = lower_bound(v1.begin(), v1.end(), ar[i]) - v1.begin();
    if (l >= 0 && l <= m - 1) {
      if (v1[l] <= ar[i]) {
        cnt = cum[l];
      } else if (v1[l] > ar[i] && l > 0) {
        cnt = cum[l - 1];
      }
      cout << cnt << " ";
    } else {
      if (l > m - 1 && v1[m - 1] <= ar[i]) {
        cout << cum[m - 1] << " ";
      } else {
        cout << -1 << " ";
      }
    }
  }
  cout << endl;
  return 0;
}
