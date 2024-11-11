#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
struct query {
  long long a, b;
  char c;
  query() {}
  query(long long a, long long b, char c) : a(a), b(b), c(c) {}
};
vector<query> res;
void get_mul(long long x, long long n) {
  if (n == 1) return;
  if (n % 2 == 0) {
    get_mul(x, n / 2);
    res.push_back(query(x * n / 2, x * n / 2, '+'));
    return;
  }
  get_mul(x, n - 1);
  res.push_back(query(x * (n - 1), x, '+'));
}
signed main() {
  long long n;
  cin >> n;
  set<long long> s;
  s.insert(n);
  long long a, b = -1;
  while (1) {
    long long sm = *s.begin();
    auto uk = s.end();
    long long bg = *(--uk);
    res.push_back(query(sm, bg, '+'));
    long long nv = sm + bg;
    vector<long long> nxt;
    for (long long elem : s) {
      res.push_back(query(elem, nv, '^'));
      nxt.push_back(bg ^ nv);
      break;
    }
    s.insert(nv);
    for (long long elem : nxt) s.insert(elem);
    for (auto x1 : s) {
      for (auto x2 : s) {
        long long g = gcd(x1, x2, a, b);
        if (g == 1) {
          if (a < 0) {
            a *= -1;
            b *= -1;
          }
          long long v1 = x1 * a;
          long long v2 = x2 * (-b);
          if ((v1 ^ v2) == 1) {
            get_mul(x1, a);
            get_mul(x2, (-b));
            res.push_back(query(v1, v2, '^'));
            cout << res.size() << endl;
            for (auto elem : res) {
              cout << elem.a << " " << elem.c << " " << elem.b << endl;
            }
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
