#include <bits/stdc++.h>
using namespace std;
const int INFL = (int)1e9;
const long long int INFLL = (long long int)1e18;
const double INFD = numeric_limits<double>::infinity();
const double PI = 3.14159265358979323846;
bool nearlyeq(double x, double y) { return abs(x - y) < 1e-9; }
bool inrange(int x, int t) { return x >= 0 && x < t; }
long long int rndf(double x) {
  return (long long int)(x + (x >= 0 ? 0.5 : -0.5));
}
long long int floorsqrt(double x) {
  long long int m = (long long int)sqrt(x);
  return m + (m * m <= (long long int)(x) ? 0 : -1);
}
long long int ceilsqrt(double x) {
  long long int m = (long long int)sqrt(x);
  return m + ((long long int)x <= m * m ? 0 : 1);
}
long long int rnddiv(long long int a, long long int b) {
  return (a / b + (a % b * 2 >= b ? 1 : 0));
}
long long int ceildiv(long long int a, long long int b) {
  return (a / b + (a % b == 0 ? 0 : 1));
}
long long int gcd(long long int m, long long int n) {
  if (n == 0)
    return m;
  else
    return gcd(n, m % n);
}
template <typename val_t, typename bsargv_t>
val_t lower_binary_search(val_t l, val_t r, const bsargv_t &bsargv,
                          bool (*evalfunc)(val_t, const bsargv_t &)) {
  if (r - l == 1) {
    if (evalfunc(l, bsargv))
      return l;
    else
      return l - 1;
  }
  val_t m = (l + r) / 2;
  if (evalfunc(m, bsargv))
    return lower_binary_search<val_t, bsargv_t>(m, r, bsargv, evalfunc);
  else
    return lower_binary_search<val_t, bsargv_t>(l, m, bsargv, evalfunc);
}
struct bsargv_t {
  vector<long long int> tasks;
  vector<long long int> sorted;
  long long int m;
  long long int t;
};
long long int last_d;
bool evalfunc(int val, const bsargv_t &bsargv) {
  long long int d = bsargv.sorted[val - 1];
  long long int cnt = 0, cntbuf = 0, sum = 0, sumbuf = 0;
  for (int i = 0; i < (int)bsargv.tasks.size(); i++) {
    if (bsargv.tasks[i] <= d) {
      cnt++;
      cntbuf++;
      sum += bsargv.tasks[i];
      sumbuf += bsargv.tasks[i];
    }
    if (cnt == (long long int)val) {
      if (sum <= bsargv.t) {
        last_d = d;
        return true;
      } else
        return false;
    }
    if (cntbuf == bsargv.m) {
      cntbuf = 0;
      sum += sumbuf;
      sumbuf = 0;
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int q;
  cin >> q;
  for (int unused = 0; unused < (int)q; unused++) {
    int n;
    long long int m, t;
    cin >> n >> m >> t;
    vector<long long int> a(n);
    for (int i = 0; i < (int)n; i++) {
      cin >> a[i];
    }
    vector<long long int> b = a;
    sort(b.begin(), b.end());
    bsargv_t bsargv = {a, b, m, t};
    last_d = 0;
    int ans = lower_binary_search<int, bsargv_t>(1, n + 1, bsargv, evalfunc);
    cout << ans << " " << last_d << endl;
  }
}
