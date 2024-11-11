#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 113;
struct fenw {
  vector<long long> t;
  void init() { t.assign(N, 0); }
  long long getsum(int r) {
    long long result = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
    return result;
  }
  void inc(int i, long long delta) {
    for (; i < N; i = (i | (i + 1))) t[i] += delta;
  }
  long long sum_pos(int pos) {
    if (pos == 0) return getsum(pos);
    return getsum(pos);
  }
  void inc_segment(int l, int r, long long val) {
    inc(l, val);
    inc(r + 1, -val);
  }
  long long sum_segment(int l, int r) { return getsum(r) - getsum(l - 1); }
};
signed main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  fenw f1, f2, f3;
  f1.init(), f2.init(), f3.init();
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    long long pr = 0;
    res += f3.sum_pos(a) + (long long)a * i;
    for (int j = a - 1; j < N; j += a) {
      res += f1.sum_segment(j - a + 1, j) - f2.sum_segment(j - a + 1, j) * pr;
      f3.inc_segment(j - a + 1, j, -pr);
      pr += a;
    }
    f1.inc(a, a);
    f2.inc(a, 1);
    cout << res << ' ';
  }
}
