#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ts, tf, tz, n;
  long long a[100000 + 5];
  cin >> ts >> tf >> tz >> n;
  set<pair<long long, long long> > x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    x.insert({a[i], i + 5});
    x.insert({a[i] - 1ll, 1});
  }
  x.insert({ts, 1});
  x.insert({tf - tz, 1});
  long long mint = 1e15, tm = 1e15;
  for (long long t = ts; t <= tf - tz;) {
    if (x.size() == 0) break;
    pair<long long, long long> p = *x.begin();
    x.erase(x.begin());
    if (p.second == 1) {
      if (p.first <= tf - tz && max(t - p.first, 0ll) < mint) {
        mint = max(t - p.first, 0ll);
        tm = p.first;
      }
    } else {
      t = max(t, p.first) + tz;
    }
  }
  cout << tm << endl;
  return 0;
}
