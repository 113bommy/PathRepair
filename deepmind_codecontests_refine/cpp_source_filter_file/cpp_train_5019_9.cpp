#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 1e9 + 47;
const long long LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
namespace IntModulo {
const int mod = 998244353;
inline int add(int x, int y, int m = mod) {
  if (x + y < m) return x + y;
  return x + y - m;
}
inline int sub(int x, int y, int m = mod) {
  if (x >= y) return x - y;
  return x - y + m;
}
inline int mult(int x, int y, int m = mod) { return x * (long long)y % m; }
inline int power(int x, int y, int m = mod) {
  int r = 1;
  while (y) {
    if (y & 1) r = mult(r, x, m);
    x = mult(x, x, m);
    y >>= 1;
  }
  return r;
}
inline int inverse(int x, int m = mod) { return power(x, m - 2, m); }
inline void ADD(int& x, int y, int m = mod) {
  x += y;
  if (x >= m) x -= m;
}
inline void SUB(int& x, int y, int m = mod) {
  x -= y;
  if (x < 0) x += m;
}
inline void MULT(int& x, int y, int m = mod) { x = x * (long long)y % m; }
};  // namespace IntModulo
namespace Combinatorics {
using namespace IntModulo;
const int N = 10000 + 57;
int fact[N];
int inv[N];
int invFact[N];
bool inited = false;
inline int C(int n, int k) {
  return n < k ? 0 : mult(fact[n], mult(invFact[k], invFact[n - k]));
}
inline int H(int n, int k) { return C(n + k - 1, k); }
void init() {
  cerr << "Combinatorics::N"
       << " = " << Combinatorics::N << endl;
  ;
  inited = true;
  inv[1] = 1;
  for (int i = (2); i < (N); ++i) inv[i] = mult(mod - mod / i, inv[mod % i]);
  invFact[0] = fact[0] = 1;
  for (int i = (1); i < (N); ++i) {
    fact[i] = mult(i, fact[i - 1]);
    invFact[i] = mult(invFact[i - 1], inv[i]);
  }
}
};  // namespace Combinatorics
namespace BerlekampMassey {
using namespace IntModulo;
inline vector<int> BM(vector<int> x) {
  vector<int> ls, cur;
  int lf, ld;
  for (int i = (0); i < ((int)((x).size())); ++i) {
    int t = 0;
    for (int j = (0); j < ((int)((cur).size())); ++j)
      t = add(t, mult(x[i - j - 1], cur[j]));
    if (t == x[i]) continue;
    if (!(int)((cur).size())) {
      cur.resize(i + 1);
      lf = i;
      ld = sub(t, x[i]);
      continue;
    }
    int k = mult(sub(t, x[i]), inverse(ld));
    vector<int> c(i - lf - 1);
    c.push_back(k);
    for (int j = (0); j < ((int)((ls).size())); ++j)
      c.push_back(sub(0, mult(k, ls[j])));
    if ((int)((c).size()) < (int)((cur).size())) c.resize((int)((cur).size()));
    for (int j = (0); j < ((int)((cur).size())); ++j) c[j] = add(c[j], cur[j]);
    if (i - lf + (int)((ls).size()) >= (int)((cur).size())) {
      ls = cur;
      lf = i;
      ld = sub(t, x[i]);
    }
    cur = c;
  }
  return cur;
}
inline void multiply(int m, vector<int>& p, vector<int>& q, vector<int>& v) {
  vector<int> t(2 * m, 0);
  for (int i = (0); i < (m); ++i)
    for (int j = (0); j < (m); ++j) t[i + j] = add(t[i + j], mult(p[i], q[j]));
  for (int i = (2 * m) - 1; i >= (m); --i)
    for (int j = (m)-1; j >= (0); --j)
      t[i - j - 1] = add(t[i - j - 1], mult(t[i], v[j]));
  for (int i = (0); i < (m); ++i) p[i] = t[i];
}
inline int solve(vector<int> x, long long n) {
  if ((int)n < (int)((x).size())) return x[n];
  vector<int> v = BM(x);
  int m = v.size();
  if (!m) return 0;
  vector<int> s(m + 1, 0);
  vector<int> t(m + 1, 0);
  s[0] = 1;
  t[1] = 1;
  if (m == 1) t[0] = v[0];
  while (n) {
    if (n & 1) multiply(m, s, t, v);
    multiply(m, t, t, v);
    n >>= 1;
  }
  int ans = 0;
  for (int i = (0); i < (m); ++i) ans = add(ans, mult(s[i], x[i]));
  return ans;
}
};  // namespace BerlekampMassey
namespace LagrangeInterpolation {
using namespace Combinatorics;
int solve(vector<int>& y, long long x) {
  int n = (int)((y).size());
  if ((int)x < n) return y[x];
  if (!Combinatorics::inited) Combinatorics::init();
  vector<int> pref(n);
  pref[0] = 1;
  for (int i = (1); i < (n); ++i) pref[i] = mult(pref[i - 1], (x - i) % mod);
  vector<int> suf(n + 1);
  suf[n] = 1;
  for (int i = (n)-1; i >= (1); --i) suf[i] = mult(suf[i + 1], (x - i) % mod);
  int ans = 0;
  for (int i = (1); i < (n); ++i) {
    int tut = mult(
        y[i], mult(pref[i - 1],
                   mult(suf[i + 1], mult(invFact[i - 1], invFact[n - i - 1]))));
    if ((n - i) & 1)
      ans = add(ans, tut);
    else
      ans = sub(ans, tut);
  }
  return ans;
}
int powerSum(int k, long long n) {
  vector<int> y(k + 3, 0);
  for (int i = (1); i < ((int)((y).size())); ++i)
    y[i] = add(y[i - 1], power(i, k));
  return solve(y, n);
}
};  // namespace LagrangeInterpolation
using namespace IntModulo;
const int N = 10000 + 57;
int p[N];
int q[N];
int x[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  Combinatorics::init();
  p[0] = q[0] = 1;
  p[1] = inverse(m);
  q[1] = sub(1, p[1]);
  for (int i = (2); i < (N); ++i) p[i] = mult(p[i - 1], p[1]);
  for (int i = (2); i < (N); ++i) q[i] = mult(q[i - 1], q[1]);
  for (int i = (1); i < (N); ++i) x[i] = power(i, k);
  vector<int> ans(k + 1, 0);
  for (int nn = (0); nn < (k + 1); ++nn) {
    int tut = 0;
    for (int i = (1); i < (nn + 1); ++i)
      ADD(tut,
          mult(p[i], mult(q[nn - i], mult(x[i], Combinatorics::C(nn, i)))));
    ans[nn] = tut;
  }
  cout << LagrangeInterpolation::solve(ans, n) << endl;
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
