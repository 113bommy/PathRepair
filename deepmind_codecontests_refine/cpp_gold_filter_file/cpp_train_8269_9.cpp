#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b;
  cin >> n;
  vector<pair<long long int, long long int>> v;
  for (long long int i = 0; i < n; i++) {
    cin >> a;
    cin >> b;
    v.push_back(make_pair(a, b));
  }
  sort(v.begin(), v.end());
  long long int c = 0;
  for (long long int i = 0; i < n - 1; i++) {
    if (v[i].second > v[i + 1].second) {
      c = 0;
      break;
    } else {
      c = 1;
    }
  }
  if (n == 1) {
    if (v[0].first < v[0].second) {
      cout << "Happy Alex";
    } else {
      cout << "Poor Alex";
    }
  } else if (c == 0) {
    cout << "Happy Alex";
  } else {
    cout << "Poor Alex";
  }
  return 0;
}
