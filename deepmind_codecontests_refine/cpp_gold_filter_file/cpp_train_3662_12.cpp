#include <bits/stdc++.h>
using namespace std;
int main() {
  map<long long, long long> m;
  long long n, i;
  cin >> n >> i;
  vector<long long> a;
  for (long long i = 0; i < n; i++) {
    long long y;
    cin >> y;
    a.push_back(y);
    m[y]++;
  }
  long long x = (long double)(8 * i) / (long double)(n);
  long long g = 1;
  while (x--) {
    g = g * 2;
    if (g >= n) {
      cout << 0 << endl;
      return 0;
    }
  }
  long long p = g;
  if (m.size() <= p)
    cout << 0 << endl;
  else {
    vector<pair<long long, long long>> v;
    for (auto it = m.begin(); it != m.end(); it++) {
      pair<long long, long long> pa;
      pa.first = it->first;
      pa.second = it->second;
      v.push_back(pa);
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    for (long long i = 0; i < p; i++) sum = sum + v[i].second;
    long long ans = n - sum;
    for (long long i = p; i < v.size(); i++) {
      sum = sum - v[i - p].second + v[i].second;
      ans = min(ans, n - sum);
    }
    cout << ans << endl;
  }
}
