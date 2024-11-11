#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 2];
    map<long long, long long> m;
    for (long long i = 1; i <= 1000; i++) {
      m[i] = 0;
    }
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      m[a[i]]++;
    }
    vector<pair<long long, long long>> v;
    for (auto i : m) {
      v.push_back({i.first, i.second});
    }
    long long d = 0;
    sort(v.rbegin(), v.rend());
    for (long long i = 0; i < v.size(); i++) {
      d += v[i].second;
      if (d >= v[i].first) {
        cout << v[i].first << endl;
        break;
      }
    }
  }
  return 0;
}
