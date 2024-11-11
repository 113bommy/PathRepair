#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isOp(char x) { return !isdigit(x); }
bool comp(string lhs, string rhs) {
  if (lhs.size() != rhs.size()) {
    return lhs.size() < rhs.size();
  }
  return count_if(lhs.begin(), lhs.end(), isOp) <
         count_if(rhs.begin(), rhs.end(), isOp);
}
string toExp(ll p0, ll x0, ll y0, ll x1, ll y1) {
  string res;
  if (p0 != 1) {
    res += to_string(p0);
    res += '*';
  }
  res += to_string(x0);
  if (y0 != 1) {
    res += '^';
    res += to_string(y0);
  }
  if (x1 == 0) return res;
  res += '+';
  res += to_string(x1);
  if (y1 != 1) {
    res += '^';
    res += to_string(y1);
  }
  return res;
}
ll powi(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (x > (long long)(1e10) || res > (long long)(1e10)) {
      return (long long)(1e11);
    }
    if (y & 1) res = res * x;
    x = x * x;
    y >>= 1;
  }
  return res;
}
int main() {
  ll n;
  cin >> n;
  if (n == 1e10) {
    cout << "10^10" << endl;
    return 0;
  }
  string res = to_string(n);
  for (ll p = 2; p < 10; p++) {
    for (ll x0 = 2; x0 < 10; x0++) {
      for (ll y0 = 2; y0 < 10; y0++) {
        ll rest = n - p * powi(x0, y0);
        if (rest < 0) break;
        res = min(res, toExp(p, x0, y0, rest, 1), comp);
        for (ll x1 = 2; x1 < 10; x1++) {
          for (ll y1 = 2; y1 < 10; y1++) {
            ll v = rest - powi(x1, y1);
            if (v == 0) res = min(res, toExp(p, x0, y0, x1, y1), comp);
          }
        }
      }
    }
  }
  for (ll x0 = 2; x0 < 100000; x0++) {
    for (ll y0 = 2; y0 < 40; y0++) {
      ll v = powi(x0, y0);
      if (v > n) break;
      ll p = n / v;
      ll rest = n - p * v;
      if (rest >= 0) {
        res = min(res, toExp(p, x0, y0, rest, 1), comp);
      }
      rest = n - (p - 1) * v;
      if (rest >= 0) {
        res = min(res, toExp(p, x0, y0, rest, 1), comp);
      } else
        break;
    }
  }
  for (ll x0 = 2; x0 * x0 <= n; x0++) {
    for (ll y0 = 2; y0 <= 40; y0++) {
      ll v = powi(x0, y0);
      if (v > n) break;
      if (n % v == 0) {
        res = min(res, toExp(n / v, x0, y0, 0, 0), comp);
      }
    }
  }
  for (ll x0 = 2; x0 * x0 <= n; x0++) {
    for (ll y0 = 2;; y0++) {
      ll rest = n - powi(x0, y0);
      if (rest < 0) break;
      res = min(res, toExp(1, x0, y0, rest, 1), comp);
      for (ll y1 = 2; y1 < 40; y1++) {
        ll x1 = pow(rest, (long double)(1) / y1) + 1e-6;
        ll v = rest - powi(x1, y1);
        if (v == 0) res = min(res, toExp(1, x0, y0, x1, y1), comp);
      }
    }
  }
  for (ll a = 2; a < 10; a++) {
    for (ll b = 2; b < 10; b++) {
      for (ll c = 2; c < 10; c++) {
        for (ll d = 2; d < 10; d++) {
          ll v = powi(a, b);
          if (v > n) break;
          v = v * powi(c, d);
          if (n < v) break;
          ll rest = n - v;
          string back = (n == v ? string("") : "+" + to_string(d));
          res = min(res,
                    to_string(a) + "^" + to_string(b) + "*" + to_string(c) +
                        "^" + to_string(d) + back,
                    comp);
        }
      }
    }
  }
  for (ll a = 2; a < 1000; a++) {
    for (ll b = 2; b < 40; b++) {
      if (n < powi(a, b)) break;
      for (ll d = 2; d < 40; d++) {
        ll c = pow(double(n / powi(a, b)), double(1.) / d) + 1e-6;
        if (c < 2) break;
        if (powi(a, b) * powi(c, d) == n) {
          res = min(res,
                    to_string(a) + "^" + to_string(b) + "*" + to_string(c) +
                        "^" + to_string(d),
                    comp);
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
