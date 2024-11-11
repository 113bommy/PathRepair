#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v;
  long long i;
  for (i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  long long x1 = 0, x2 = 0, y = 0;
  for (i = 0; i < v.size(); i++) {
    if (v[i].first > x1) {
      x1 = v[i].second;
      continue;
    } else if (v[i].first > x2) {
      x2 = v[i].second;
      continue;
    } else {
      y = 1;
      break;
    }
  }
  if (y)
    cout << "NO";
  else
    cout << "YES";
}
