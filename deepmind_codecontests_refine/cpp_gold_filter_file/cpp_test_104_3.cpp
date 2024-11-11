#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const long long U = 998244353;
string to_string(char c) { return "'" + string(1, c) + "'"; }
string to_string(string s) { return '"' + s + '"'; }
string to_string(bool f) {
  if (f)
    return "True";
  else
    return "False";
}
string to_string(const char *s) { return to_string((string)s); }
template <typename A>
string to_string(A);
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ": " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool f = false;
  string r = "{";
  for (auto x : v) {
    if (f) r += ", ";
    r += to_string(x);
    f = true;
  }
  return r += "}";
}
template <typename A>
string to_string(vector<vector<A>> v) {
  string r;
  for (auto x : v) r += "\n" + to_string(x);
  return r;
}
long long Nerr;
template <typename A>
string to_string(A *p) {
  return to_string(vector<A>(p, p + Nerr));
}
void err(istream_iterator<string>) { cerr << '\n'; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << to_string(a) << "; ";
  err(++it, args...);
}
template <typename T>
void kek(T ans) {
  cout << ans << '\n';
  exit(0);
}
signed main() {
  ios_base::sync_with_stdio(0);
  long long TESTS = 1;
  cin >> TESTS;
  while (TESTS--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++) cin >> a[i] >> b[i];
    vector<pair<long long, long long>> ranges;
    for (long long i = 0; i < n; i++) {
      long long l = (long long)1e15;
      if (b[i] >= m)
        l = 0;
      else
        l = m - b[i];
      long long r = 0;
      if (a[i] >= m)
        r = m;
      else
        r = a[i];
      ranges.push_back({l, r});
    }
    long long p = n * m;
    for (long long i = 0; i < n; i++) p += a[i] - b[i];
    long long mnsum = 0;
    long long mxsum = 0;
    for (auto j : ranges) {
      mnsum += j.first;
      mxsum += j.second;
    }
    if (p >= 2 * mnsum and p <= 2 * mxsum) {
      if (p % 2 == 0)
        cout << 0 << '\n';
      else
        cout << 1 << '\n';
      long long diff = p - 2 * mnsum;
      for (auto j : ranges) {
        long long r = (j.second - j.first);
        long long x = j.first;
        long long use = min(diff / 2, r);
        diff -= 2 * use;
        cout << x + use << " " << m - (x + use) << '\n';
      }
    } else {
      long long ans = min(abs(2 * mnsum - p), abs(2 * mxsum - p));
      cout << ans << '\n';
      if (ans == abs(2 * mnsum - p)) {
        for (auto j : ranges) {
          cout << j.first << " " << m - j.first << '\n';
        }
      } else if (ans == abs(2 * mxsum - p)) {
        for (auto j : ranges) {
          cout << j.second << " " << m - j.second << '\n';
        }
      }
    }
  }
}
