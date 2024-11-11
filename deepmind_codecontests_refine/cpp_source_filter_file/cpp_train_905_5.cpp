#include <bits/stdc++.h>
using namespace std;
long long abs(long long, long long);
void solve() {
  long long n, x;
  cin >> n;
  vector<pair<long long, long long>> v;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    v.push_back(make_pair(x, i));
  }
  sort(v.begin(), v.end());
  if (n == 1)
    cout << "Exemplary pages."
         << "\n";
  else {
    if (v[0].first == v[v.size() - 1].first)
      cout << "Exemplary pages."
           << "\n";
    else {
      for (long long i = 1; i < v.size() - 2; i++) {
        if (v[i].first != v[i + 1].first) {
          cout << "Unrecoverable configuration."
               << "\n";
          return;
        }
      }
      if ((v[v.size() - 1].first + v[0].first) / 2 != v[1].first) {
        cout << "Unrecoverable configuration."
             << "\n";
        return;
      }
      long long y = v[v.size() - 1].first - v[0].first;
      if (y % 2 != 0) {
        cout << "Unrecoverable configuration."
             << "\n";
        return;
      }
      cout << (v[v.size() - 1].first - v[0].first) / 2 << " ml. from cup #"
           << v[0].second + 1 << " to cup #" << v[v.size() - 1].second + 1
           << "."
           << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long TESTS = 1;
  while (TESTS--) {
    solve();
  }
  return 0;
}
long long abs(long long a, long long b) {
  if (a > b)
    return a - b;
  else
    return b - a;
}
