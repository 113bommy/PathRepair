#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int n;
  cin >> n;
  pair<long long int, long long int> a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  vector<long long int> v;
  long long int c = 0;
  for (long long int i = 0; i < n; i++) {
    if (abs(c + a[i].first) >= abs(c - a[i].second)) {
      c = c - a[i].second;
      v.push_back(0);
    } else {
      c = c + a[i].first;
      v.push_back(1);
    }
  }
  if (abs(c) <= 500) {
    for (long long int i = 0; i < n; i++) {
      if (v[i] == 1) {
        cout << "A";
      } else {
        cout << "G";
      }
    }
  } else {
    cout << -1;
  }
}
