#include <bits/stdc++.h>
using namespace std;
const int MX = 100005;
int mod_mult(long long a, long long b, int m) { return (a * b) % m; }
int exp(int a, int b, int m) {
  int res = 1;
  while (b) {
    if (b % 2 == 1) res = mod_mult(res, a, m);
    a = mod_mult(a, a, m);
    b /= 2;
  }
  return res;
}
map<int, vector<pair<int, int>>> Pr;
map<int, int> Phi;
int phi(int n) {
  if (Phi[n] == 0) {
    int m = n;
    int res = n;
    for (int x = 2; x * x <= m; x++) {
      if (m % x == 0) {
        while (m % x == 0) m /= x;
        res -= res / x;
      }
    }
    if (m > 1) {
      res -= res / m;
    }
    Phi[n] = res;
  }
  return Phi[n];
}
vector<pair<int, int>> pr(int n) {
  if (Pr[n].empty()) {
    auto& M = Pr[n];
    int m = n;
    for (int x = 2; x * x <= m; x++) {
      if (m % x == 0) {
        M.emplace_back(x, 1);
        while (m % x == 0) {
          M.back().second *= x;
          m /= x;
        }
      }
    }
    if (m > 1) {
      M.emplace_back(m, m);
    }
  }
  return Pr[n];
}
int a[MX];
int nxt_one[MX];
int Calc(int i, int r, int x, int m) {
  if (m == 1) return 0;
  if (i == r) {
    return exp(a[i], x, m);
  }
  vector<pair<int, int>> M = pr(m);
  int q = 1;
  int b = 1;
  for (auto p : M) {
    if (a[i] % p.first == 0) {
      q *= p.second;
    } else {
      b *= p.second;
    }
  }
  x = Calc(i + 1, r, x, phi(b));
  int tmp = exp(a[i], x, b);
  int q_inv = exp(q, phi(b) - 1, b);
  int res = mod_mult(tmp, q_inv, b);
  res *= q;
  return res;
}
int main() {
  int n, m;
  ignore = scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    ignore = scanf("%d", a + i);
  }
  nxt_one[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    if (a[i] == 1) {
      nxt_one[i] = i;
    } else {
      nxt_one[i] = nxt_one[i + 1];
    }
  }
  int q;
  ignore = scanf("%d", &q);
  while (q--) {
    int l, r;
    ignore = scanf("%d %d", &l, &r);
    r = min(r, nxt_one[l] - 1);
    if (l > r) {
      printf("%d\n", 1 % m);
      continue;
    }
    int x = 1;
    while (r >= l) {
      int cur = 1;
      int t = x;
      while (t && cur < 30) {
        cur *= a[r];
        t--;
      }
      if (cur >= 30) break;
      x = cur;
      r--;
    }
    if (l > r) {
      printf("%d\n", x % m);
      continue;
    }
    int tmp = Calc(l, r, x, m);
    printf("%d\n", tmp);
  }
}
