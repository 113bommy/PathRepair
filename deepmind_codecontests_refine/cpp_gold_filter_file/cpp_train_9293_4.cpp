#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  string sep;
  for (const auto &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename T, size_t size>
ostream &operator<<(ostream &os, const array<T, size> &arr) {
  os << '{';
  string sep;
  for (const auto &x : arr) os << sep << x, sep = ", ";
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
long long n, m, l, r;
int main() {
  cin >> n >> m >> l >> r;
  vector<array<long long, 4>> res(n + 1, {-1, -1, -1, -1});
  for (long long g = 1; g <= n / 2; g++) {
    for (long long x1 = g; x1 <= n; x1 += g) {
      long long k = x1 / g;
      long long min_y = (l - 1) / x1 + 1;
      long long max_y = min(m, r / x1);
      long long min_t = 1;
      long long max_t = n / g - k;
      if (min_t <= max_t && min_y <= max_y) {
        for (long long t = min_t;
             t <= max_t && t * (k + t) <= max_y && res[x1][0] == -1; t++) {
          long long min_p = (min_y - 1) / (k + t) + 1;
          long long max_p = max_y / (k + t);
          if (min_p <= max_p) {
            res[x1][0] = x1;
            res[x1][1] = min_p * (k + t);
            res[x1][2] = g * (k + t);
            res[x1][3] = min_p * k;
            break;
          }
        }
        for (long long p = 1; p * (k + p) <= max_y && res[x1][0] == -1; p++) {
          long long new_min_t = max(min_t, (min_y - 1) / p + 1 - k);
          long long new_max_t = min(max_t, max_y / p - k);
          if (new_min_t <= new_max_t) {
            res[x1][0] = x1;
            res[x1][1] = p * (k + new_min_t);
            res[x1][2] = g * (k + new_min_t);
            res[x1][3] = p * k;
            break;
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (res[i][0] == -1)
      cout << "-1\n";
    else
      cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << ' '
           << res[i][3] << '\n';
  }
  return 0;
}
