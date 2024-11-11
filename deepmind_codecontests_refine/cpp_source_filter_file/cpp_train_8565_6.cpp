#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) {
    return a.first > b.first;
  } else {
    return a.second < b.second;
  }
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> v[i].second;
      sm = sm + v[i].second;
    }
    sort(v.begin(), v.end(), cmp);
    long long s = 0;
    if (v[n - 1].first >= sm) {
      cout << sm << "\n";
      continue;
    } else {
      for (int i = 0; i < n; i++) {
        if (s + v[i].second <= v[i].first) {
          s = s + v[i].second;
        } else {
          s = max(s, (long long)v[i].first);
          break;
        }
      }
      if (s == 0) {
        cout << v[0].first << "\n";
      } else {
        cout << s << "\n";
      }
    }
  }
  return 0;
}
