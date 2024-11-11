#include <bits/stdc++.h>
using namespace std;
const int N = 100000, mod = 1000000007, inv2 = 500000004;
int Power(int a, int k, int p) {
  int res = 1;
  for (; k; k >>= 1, a = 1LL * a * a % p)
    if (k & 1) res = 1LL * res * a % p;
  return res;
}
int Get_inv(int a) { return Power(a, mod - 2, mod); }
char s[N + 9];
int n;
void into() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
}
struct number {
  int len[2], val[2];
  number() {
    len[0] = len[1] = 1;
    val[0] = val[1] = 0;
  }
  number operator+(const char &p) const {
    number res;
    res.len[0] = 1LL * len[0] * 10 % mod;
    res.len[1] = 1LL * len[1] * 10 % (mod - 1);
    res.val[0] = (1LL * val[0] * 10 + p - '0') % mod;
    res.val[1] = (1LL * val[1] * 10 + p - '0') % (mod - 1);
    return res;
  }
  number operator+(const number &p) const {
    number res;
    res.len[0] = 1LL * len[0] * p.len[0] % mod;
    res.len[1] = 1LL * len[1] * p.len[1] % (mod - 1);
    res.val[0] = (1LL * val[0] * p.len[0] + p.val[0]) % mod;
    res.val[1] = (1LL * val[1] * p.len[1] + p.val[1]) % (mod - 1);
    return res;
  }
  number operator*(const number &p) const {
    number res;
    res.len[0] = Power(p.len[0], val[1], mod);
    if (p.len[0] == 1)
      res.val[0] = 1LL * p.val[0] * val[0] % mod;
    else {
      res.val[0] = (mod + 1 - Power(p.len[0], val[1], mod)) % mod;
      res.val[0] = 1LL * res.val[0] * Get_inv((mod + 1 - p.len[0]) % mod) % mod;
      res.val[0] = 1LL * res.val[0] * p.val[0] % mod;
    }
    return res;
  }
};
int Calc0(int a, int n) {
  return 1LL * Get_inv((mod + 1 - a) % mod) * (mod + 1 - Power(a, n, mod)) %
         mod;
}
int Calc1(int a, int n0, int n1) {
  if (a == 1) return 1LL * n1 * (mod - 1 + n1) % mod * inv2 % mod;
  int res = 1LL * (mod - 1 + n1) * Power(a, n0, mod) % mod;
  res = (res -
         1LL * Get_inv((mod + 1 - a) % mod) * (mod + 1 - Power(a, n0, mod)) %
             mod +
         1 + mod) %
        mod;
  return 1LL * res * Get_inv((mod - 1 + a) % mod) % mod;
}
void Get_(vector<int> &a, int &c, int &v) {
  int n = a.size();
  if (n == 1 && a[0] == 1) return;
  for (int i = 1; i < n; ++i) {
    int pw00 = Power(10, i - 1, mod - 1), pw01 = Power(10, i - 1, mod);
    int pw10 = Power(10, i, mod - 1), pw11 = Power(10, i, mod);
    int nc = 9LL * pw00 * i % (mod - 1);
    int nv = (1LL * (mod - 1 + pw11) * Calc0(pw11, 9LL * pw00 % (mod - 1)) +
              mod - Calc1(pw11, 9LL * pw00 % (mod - 1), 9LL * pw01 % mod)) %
             mod;
    c = (c + nc) % (mod - 1);
    v = (1LL * v * Power(10, nc, mod) + nv) % mod;
  }
  --a.back();
  int pw = Power(10, n, mod), now = Power(10, n - 1, mod);
  for (int i = n - 1; i >= 0; --i) {
    if (!a[i]) continue;
    int pw00 = Power(10, i, mod - 1), pw01 = Power(10, i, mod);
    now = (now + 1LL * a[i] * pw01) % mod;
    int nc = 1LL * a[i] * pw00 * n % mod;
    int nv =
        (1LL * (mod - 1 + now) * Calc0(pw, 1LL * a[i] * pw00 % (mod - 1)) +
         mod -
         Calc1(pw, 1LL * a[i] * pw00 % (mod - 1), 1LL * a[i] * pw01 % mod)) %
        mod;
    c = (c + nc) % (mod - 1);
    v = (1LL * v * Power(10, nc, mod) + nv) % mod;
  }
}
number Get(int p) {
  vector<int> a, b;
  for (int i = p - 1; i >= 1 && s[i] >= '0' && s[i] <= '9'; --i)
    a.push_back(s[i] - '0');
  for (int i = p + 1; i <= n && s[i] >= '0' && s[i] <= '9'; ++i)
    b.push_back(s[i] - '0');
  reverse(b.begin(), b.end());
  b.push_back(0);
  for (int i = 0; i <= n; ++i)
    if (b[i] < 9) {
      ++b[i];
      break;
    } else
      b[i] = 0;
  if (!b.back()) b.pop_back();
  int ca = 0, cb = 0, va = 0, vb = 0;
  Get_(a, ca, va);
  Get_(b, cb, vb);
  number res;
  res.len[0] = Power(10, (cb - ca + mod - 1) % (mod - 1), mod);
  res.val[0] = (vb - 1LL * va * res.len[0] % mod + mod) % mod;
  return res;
}
vector<int> e[N + 9];
number a[N + 9];
int cn;
void Get_tree() {
  static int sta[N + 9], cst;
  number num1 = number() + '1';
  int flag = 0;
  a[sta[cst = 1] = cn = 1] = num1;
  e[1].push_back(sta[++cst] = ++cn);
  for (int i = 1; i <= n;)
    if (s[i] == '(') {
      int k = sta[cst];
      if (!flag) a[k] = num1;
      e[k].push_back(sta[++cst] = ++cn);
      flag = 0;
      ++i;
    } else if (s[i] == ')') {
      --cst;
      ++i;
    } else if (s[i] == '+') {
      --cst;
      int k = sta[cst];
      e[k].push_back(sta[++cst] = ++cn);
      flag = 0;
      ++i;
    } else {
      int k = sta[cst];
      flag = 1;
      number x;
      for (; i <= n && s[i] >= '0' && s[i] <= '9'; ++i) x = x + s[i];
      if (s[i] == '-') {
        a[k] = Get(i);
        for (++i; i <= n && s[i] >= '0' && s[i] <= '9'; ++i)
          ;
      } else
        a[k] = x;
    }
}
number ans;
number Dfs_ans(int k) {
  if (e[k].empty()) return a[k];
  number res;
  for (int vs = e[k].size(), i = 0; i < vs; ++i) {
    int y = e[k][i];
    res = res + Dfs_ans(y);
  }
  return a[k] * res;
}
void work() {
  Get_tree();
  ans = Dfs_ans(1);
}
void outo() { printf("%d\n", ans.val[0]); }
int main() {
  into();
  work();
  outo();
  return 0;
}
