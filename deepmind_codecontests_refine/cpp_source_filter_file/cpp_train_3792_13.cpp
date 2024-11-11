#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
const long double pi = acos(-1);
const long long MOD = 1e9 + 7;
int N;
int A[1010];
inline int mod(int a) {
  a %= MOD;
  if (a < 0) a += MOD;
  return a;
}
inline int mul(int a, int b) { return mod(int(mod(a) * 1LL * mod(b) % MOD)); }
inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}
int solve(int l, int r) {
  if (l >= r) return 0;
  int m = (l + r) / 2;
  int res = add(solve(l, m), solve(m + 1, r));
  int delta = 10010;
  vector<int> fleft(21010);
  vector<int> fright(21010);
  vector<int> curfleft(21010);
  vector<int> curfright(21010);
  curfleft[delta + 0] = 1;
  curfright[delta + 0] = 1;
  for (int l2 = m; l2 >= l; l2--) {
    vector<int> newfleft(22222);
    for (int n = -10000; n <= 10000; n++) {
      int nn = n + delta;
      if (curfleft[nn] == 0) continue;
      int newn;
      newn = nn + A[l2];
      if (0 <= newn && newn <= 21000)
        newfleft[newn] = add(newfleft[newn], curfleft[nn]);
      newn = nn - A[l2];
      if (0 <= newn && newn <= 21000)
        newfleft[newn] = add(newfleft[newn], curfleft[nn]);
    }
    curfleft = newfleft;
    for (int n = -10000; n <= 10000; n++)
      fleft[n + delta] = add(fleft[n + delta], curfleft[n + delta]);
  }
  for (int r2 = m + 1; r2 <= r; r2++) {
    vector<int> newfright(22222);
    for (int n = -10000; n <= 10000; n++) {
      int nn = n + delta;
      if (curfright[nn] == 0) continue;
      int newn;
      newn = nn + A[r2];
      if (0 <= newn && newn <= 21000)
        newfright[newn] = add(newfright[newn], curfright[nn]);
      newn = nn - A[r2];
      if (0 <= newn && newn <= 21000)
        newfright[newn] = add(newfright[newn], curfright[nn]);
    }
    curfright = newfright;
    for (int n = -10000; n <= 10000; n++)
      fright[n + delta] = add(fright[n + delta], curfright[n + delta]);
  }
  res = add(res, mul(fleft[0 + delta], fright[0 + delta]));
  for (int i = 1; i <= 1000; i++) {
    res = add(res, mul(fleft[i + delta], fright[-i + delta]));
    res = add(res, mul(fleft[-i + delta], fright[i + delta]));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.precision(15);
  cout << fixed;
  cout.tie(0);
  cin >> N;
  for (int(i) = 1, j123 = N; (i) <= j123; (i)++) cin >> A[i];
  cout << solve(1, N) << '\n';
}
