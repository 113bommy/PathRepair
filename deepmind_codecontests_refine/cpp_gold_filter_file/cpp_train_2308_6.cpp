#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (auto u : v) {
    os << u;
    os << ",";
  }
  os << "]"
     << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
  os << "{";
  for (auto u : s) {
    os << u;
    if (u != *s.rbegin()) os << ",";
  }
  os << "}"
     << "\n";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "{";
  os << p.first << "," << p.second;
  os << "}"
     << "\n";
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
  for (auto p : mp) os << p.first << " : " << p.second << "\n";
  return os;
}
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(3);
}
int32_t main() {
  boost();
  long long t = 1;
  while (t--) {
    long long a[3], d;
    cin >> a[0] >> a[1] >> a[2] >> d;
    sort(a, a + 3);
    if (a[1] >= a[0] + d && a[2] >= a[1] + d)
      cout << 0 << "\n";
    else {
      if (a[1] >= a[0] + d) {
        if (a[2] >= a[0] + 2 * d) {
          long long get = a[2] - d;
          long long ans = a[1] - get;
          cout << ans << "\n";
        } else {
          long long have = (a[1] + d) - a[2];
          cout << have << "\n";
        }
      } else if (a[2] >= a[1] + d) {
        if (a[2] >= a[0] + 2 * d) {
          long long get = a[0] + d;
          long long ans = get - a[1];
          cout << ans << "\n";
        } else {
          long long have = abs((a[1] - d) - a[0]);
          cout << have << "\n";
        }
      } else {
        long long ans = abs(d - (a[1] - a[0]));
        ans = ans + abs(d - (a[2] - a[1]));
        cout << ans << "\n";
      }
    }
  }
  return 0;
}
