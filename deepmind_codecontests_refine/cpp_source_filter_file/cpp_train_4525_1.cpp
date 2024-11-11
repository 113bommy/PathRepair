#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
const double PI = acos(-1.0);
const int EPS = (1e-10);
const int N = 1e5 * 2 + 10;
const int inf = 1e9 * 2 + 10;
const ll INF = 1e18 * 2 + 10;
const int MOD = 1e9 + 7;
int nxt() {
  int x;
  cin >> x;
  return x;
}
int fcmp(double a, double b) {
  return (fabs(a - b) < EPS ? 0 : a > b ? 1 : -1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int> > a(n + 1);
  map<int, int> mp;
  int s = 1;
  for (int i = (1); i <= (n); ++i) {
    cin >> a[i].first;
    if (s < 3) s *= ++mp[a[i].first];
    a[i].second = i;
  }
  sort((a).begin(), (a).end());
  if (s >= 3) {
    cout << "YES\n";
    for (int i = (0); i <= (2); ++i) {
      int t = i + 1;
      for (int i = (1); i <= (n); ++i) {
        cout << a[i].second << " ";
        if (a[i].first == a[i - 1].first) {
          t--;
          swap(a[i], a[i - 1]);
        }
      }
      cout << '\n';
    }
  } else
    cout << "NO";
  return 0;
}
