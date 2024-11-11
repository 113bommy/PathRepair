#include <bits/stdc++.h>
using namespace std;
long long ans[4];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, y1, y2, x;
  cin >> n >> y1;
  long long a = 0, b = 0;
  vector<long long> v1(n);
  for (long long i = 0; i < n; i++) {
    cin >> x;
    v1[i] = x;
    if (x % 2)
      a++;
    else
      b++;
  }
  cin >> m >> y2;
  vector<long long> v2(m);
  for (long long i = 0; i < m; i++) {
    cin >> x;
    v2[i] = x;
    if (x % 2)
      b++;
    else
      a++;
  }
  long long lel = max({2ll, a, b});
  for (long long mult = 2; mult <= 1e9; mult *= 2) {
    long long gege = mult >> 1;
    map<long long, long long> mm;
    for (long long i = 0; i < n; i++) {
      mm[v1[i] % mult]++;
    }
    for (long long i = 0; i < m; i++) {
      mm[(v2[i] + gege) % mult]++;
    }
    for (auto &i : mm) lel = max(lel, i.second);
  }
  cout << lel;
  return 0;
}
