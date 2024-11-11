#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const double eps = 1e-6;
const int BIG = 1e6;
pair<long long, int> a[N];
long long dp[N];
int P[N];
struct FEN {
  vector<long long> T;
  int n;
  FEN() {
    n = 0;
    T.clear();
  }
  FEN(int sz) {
    n = sz;
    T.clear();
    T.resize(sz + 1);
  }
  void clear(int sz) {
    n = sz;
    T.clear();
    T.resize(sz + 1);
  }
  void update(int i, long long val) {
    while (i <= n) {
      T[i] = max(T[i], val);
      i += i & -i;
    }
  }
  long long query(int i) {
    long long ans = 0;
    while (i > 0) {
      ans = max(ans, T[i]);
      i -= i & -i;
    }
    return ans;
  }
} b(N);
int main() {
  clock_t tm = clock();
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int __t = 1;
  for (int _t = 1; _t <= __t; ++_t) {
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n - 1; ++i) {
      long long r, h;
      cin >> r >> h;
      a[i].first = r * r * h;
      a[i].second = -i;
    }
    sort(a, a + n);
    for (int i = 0; i <= n - 1; ++i) {
      P[-a[i].second] = i;
    }
    for (int i = 0; i <= n - 1; ++i) {
      dp[i] = max(dp[i], a[P[i]].first + b.query(P[i]));
      b.update(P[i] + 1, dp[i]);
    }
    double pi = 2 * acos(0);
    cout << fixed << setprecision(12) << pi * b.query(n) << "\n";
  }
  tm = clock() - tm;
  cerr << (float)(tm) / CLOCKS_PER_SEC << "\n";
  return 0;
}
