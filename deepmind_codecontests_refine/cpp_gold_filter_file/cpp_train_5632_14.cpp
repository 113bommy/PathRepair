#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long k, n;
  cin >> k >> n;
  map<long long, long long> m;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    if (m.count(x) == 0) {
      v.push_back(x);
      m[x] = 0;
    }
    m[x]++;
  }
  long long days = 0;
  for (long long i = 1; i <= n; i++) {
    long long people = 0;
    for (long long j = 0; j < (long long)v.size(); j++) {
      people += m[v[j]] / i;
    }
    if (people >= k) {
      days = i;
    }
  }
  cout << days << "\n";
  return 0;
}
