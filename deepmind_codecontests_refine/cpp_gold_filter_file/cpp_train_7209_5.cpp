#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char& ch) {
  string s = "";
  s += ch;
  return "'" + s + "', ";
}
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
const long long mod = (long long)1000000007;
const long long inf = (long long)2e18;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(9);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long> > a(m + 1, {inf, -1});
    for (long long i = 1; i <= m; ++i) {
      long long x, y;
      cin >> x >> y;
      a[i] = {x, y};
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    vector<long long> pre(m + 1, 0);
    for (long long i = 1; i <= m; ++i) {
      pre[i] = pre[i - 1] + a[i].first;
    }
    long long ans = 0;
    42;
    for (long long i = 1; i <= m; ++i) {
      long long a_val = a[i].first, b_val = a[i].second;
      long long ind = -1, lo = 0, hi = m;
      while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        42;
        if (a[mid].first > b_val) {
          ind = max(ind, mid);
          42;
          lo = mid + 1;
        } else
          hi = mid - 1;
      }
      long long su = pre[ind];
      assert(ind >= 0 && ind <= m);
      if (n <= ind) {
        ans = max(ans, pre[n]);
      } else {
        long long cp = n;
        cp -= ind;
        if (a_val <= b_val) {
          --cp;
          su += a_val;
        }
        su += cp * b_val;
        ans = max(ans, su);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
