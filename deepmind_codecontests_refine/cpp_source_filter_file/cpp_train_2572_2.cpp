#include <bits/stdc++.h>
using namespace std;
long long n, m, ost, r, ch, zap, t;
pair<long long, long long> a[300000];
long long b[300000];
set<long long> mn;
int main() {
  cin >> n >> m;
  ost = n / m;
  ch = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = 0;
  }
  for (long long i = 0; i <= m - 1; ++i) mn.insert(i);
  for (long long i = 1; i <= n; ++i) {
    if (mn.size() == 0) break;
    if (mn.lower_bound(a[i].first % m) != mn.end()) {
      r = *mn.lower_bound(a[i].first % m);
    } else
      r = *mn.begin();
    if (b[r] < ost) {
      ++b[r];
      if (a[i].first % m <= r) {
        ch += r - a[i].first % m;
        a[i].first += r - a[i].first % m;
      } else {
        ch += m - a[i].first + r;
        a[i].first += m - a[i].first + r;
      }
      if (b[r] == ost) mn.erase(r);
      a[i].second = 1;
    }
  }
  cout << ch << endl;
  for (long long i = 1; i <= n; ++i) cout << a[i].first << " ";
}
