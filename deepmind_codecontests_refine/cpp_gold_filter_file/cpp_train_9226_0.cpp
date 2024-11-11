#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
const long long INF = (long long)1e18;
const int inf = (int)1e9;
const int N = (int)10000;
const int MOD = (int)1e9 + 7;
const int base = 998244353;
const double eps = (double)1e-9;
const double PI = acos(-1.0);
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n;
int x[N];
void in();
void out();
void precalc();
void solv();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  in();
  precalc();
  solv();
  out();
}
void in() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i];
}
void precalc() {}
void solv() {
  for (int i = 1; i <= n; ++i) {
    bool flag = 1;
    for (int j = 0; j <= 100; ++j)
      if (3 * j <= x[i] && (x[i] - 3 * j) % 7 == 0) {
        cout << "YES\n";
        flag = 0;
        break;
      }
    if (flag) cout << "NO\n";
  }
}
void out() {}
