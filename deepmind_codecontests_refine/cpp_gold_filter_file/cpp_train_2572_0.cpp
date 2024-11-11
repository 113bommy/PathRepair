#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, m;
  cin >> n >> m;
  long long a[n];
  vector<long long> arr[m];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    arr[a[i] % m].push_back(i);
  }
  vector<pair<long long, long long> > ava;
  long long l = 2, req = n / m;
  long long ans = 0;
  while (l--) {
    for (long long i = 0; i < m; i++) {
      if (arr[i].size() > req) {
        while (arr[i].size() > req) {
          long long p = arr[i].back();
          arr[i].pop_back();
          ava.push_back(make_pair(i, p));
        }
      } else if (arr[i].size() < req) {
        while (arr[i].size() < req && (!ava.empty())) {
          pair<long long, long long> p = ava.back();
          ava.pop_back();
          long long fir = p.first;
          long long sec = p.second;
          arr[i].push_back(sec);
          a[sec] += ((i - fir + m) % m);
          ans += ((i - fir + m) % m);
        }
      }
    }
  }
  cout << ans << endl;
  for (long long i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
