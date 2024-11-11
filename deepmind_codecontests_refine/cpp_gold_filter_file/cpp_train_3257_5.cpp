#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  return ((a.second < b.second) || (a.second == b.second && a.first < b.first));
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, w, sum = 0, flag = 0;
    cin >> n >> w;
    long long mins = (w + 1) / 2;
    vector<pair<long long, long long>> v(n, make_pair(0, 0)), a;
    for (long long i = 0; i < n; ++i) {
      v[i].first = i + 1;
      cin >> v[i].second;
    }
    sort(v.begin(), v.end(), comp);
    for (long long i = n - 1; i >= 0; --i) {
      if (v[i].second <= w && sum + v[i].second <= w) {
        sum += v[i].second;
        a.push_back(v[i]);
      }
      if (sum >= mins) {
        flag = 1;
        break;
      }
    }
    sort(a.begin(), a.end());
    if (flag != 1)
      cout << -1 << endl;
    else {
      cout << a.size() << endl;
      for (auto i : a) {
        cout << i.first << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
