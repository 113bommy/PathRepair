#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
void printa(long long *q, long long tam) {
  for (long long i = 0; i < tam; ++i) {
    cout << q[i] << " ";
  }
  cout << "\n";
}
const long long M = 1000000007;
long long fexp(long long a, long long b, long long M) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % M;
    }
    b >>= 1;
    a = a * a % M;
  }
  return res;
}
long long inv(long long x, long long M) { return fexp(x, M - 2, M); }
void mul(long long &x, long long y) {
  x *= y;
  x %= M;
}
void _div(long long &x, long long y) {
  x *= inv(y, M);
  x %= M;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n << "\n";
    return 0;
  }
  long long y[k + 4];
  y[k + 3] = 1;
  y[0] = 0;
  for (long long i = 1; i <= k + 2; i++) {
    y[i] = fexp(i, k, M);
    y[i] += y[i - 1];
    if (y[i] >= M) {
      y[i] -= M;
    }
  }
  if (n <= k + 1) {
    cout << y[n] << "\n";
    return 0;
  }
  long long ans = 0;
  long long val = 0;
  long long z = -k - 1;
  long long w = 1;
  for (long long i = 1; i <= k + 2; i++) {
    if (i == 1) {
      val = 1;
      for (long long j = 2; j <= k + 2; j++) {
        mul(val, n - j);
        _div(val, 1 - j);
      }
    }
    ans += val;
    if (ans >= M)
      ans -= M;
    else if (ans < 0)
      ans += M;
    mul(val, y[i + 1]);
    _div(val, y[i]);
    mul(val, n - i);
    _div(val, n - i - 1);
    mul(val, z);
    _div(val, w);
    z++;
    w++;
  }
  cout << ans << "\n";
}
