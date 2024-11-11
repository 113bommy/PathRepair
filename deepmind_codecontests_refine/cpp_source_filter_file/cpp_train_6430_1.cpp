#include <bits/stdc++.h>
using namespace std;
void guan() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long mod = 998244353;
const long long mod2 = mod - 1;
const int INF = 0x7FFFFFFF;
const long long LINF = 0x7FFFFFFFFFFFFFFF;
const double pi = acos(-1.0);
const long long maxx = 1LL << 61;
const double eps = 1e-8;
long long qpow(long long a, long long n) {
  long long sum = 1;
  while (n) {
    if (n & 1) sum = sum * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return sum;
}
const int maxn = 4040404;
pair<int, int> a[111], b[111];
int main() {
  guan();
  int t = 1;
  int n, m;
  int d;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) {
      cin >> a[i].first >> a[i].second;
      if (a[i].first > a[i].second) swap(a[i].first, a[i].second);
    }
    for (int i = 1; i <= m; ++i) {
      cin >> b[i].first >> b[i].second;
      if (b[i].first > b[i].second) swap(b[i].first, b[i].second);
    }
    int ok = 1, pre = 0, two = 0;
    for (int i = 1; i <= n && ok; i++) {
      int ta = 0, tb = 0;
      for (int j = 1; j <= m && ok; j++) {
        if (a[i].first == b[j].first && a[i].second == b[j].second)
          continue;
        else if (a[i].first == b[j].first || a[i].first == b[j].second)
          ta = 1;
        else if (a[i].second == b[j].first || a[i].second == b[j].second)
          tb = 1;
      }
      if (ta && tb)
        ok = 0;
      else if (ta) {
        if (a[i].first != pre) pre = a[i].first, two++;
      } else if (tb) {
        if (a[i].second != pre) pre = a[i].second, two++;
      }
    }
    for (int i = 1; i <= m && ok; i++) {
      int ta = 0, tb = 0;
      for (int j = 1; j <= n && ok; j++) {
        if (b[i].first == a[j].first && b[i].second == a[j].second)
          continue;
        else if (b[i].first == a[j].first || b[i].first == a[j].second)
          ta = 1;
        else if (b[i].second == a[j].first || b[i].second == a[j].second)
          tb = 1;
      }
      if (ta && tb) ok = 0;
    }
    if (ok) {
      if (two > 1)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    } else
      cout << -1 << endl;
  }
  return 0;
}
