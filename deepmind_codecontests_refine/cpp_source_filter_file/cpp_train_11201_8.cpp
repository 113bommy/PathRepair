#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio();
  cin.tie(0);
  cout.tie(0);
}
const long long maxn = 1e5 + 123;
const long long inf = 1e9 + 123;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
pair<int, int> a[maxn];
int main() {
  boost();
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    if (a[i].first < a[i].second) {
      cout << "rated";
      return 0;
    }
  }
  for (int i = 2; i <= n; i++) {
    if (a[i].first > a[i - 1].first) {
      cout << "unrated";
      return 0;
    }
  }
  cout << "maybe";
  return 0;
}
