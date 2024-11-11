#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
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
void debug_out() { cout << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
vector<pair<long long, long long> > taps;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, z, k;
  long double t;
  cout.precision(11);
  cout << fixed;
  cin >> n >> t;
  taps.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> taps[i].second;
  }
  for (int i = 0; i < n; i++) {
    cin >> taps[i].first;
  }
  sort(taps.begin(), taps.end());
  for (int i = 0; i < n; i++) {
    swap(taps[i].first, taps[i].second);
  }
  long double total = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    total += (taps[i].first * taps[i].second);
    cnt += taps[i].first;
  }
  total /= cnt;
  bool ok = true;
  if (total < t) {
    reverse(taps.begin(), taps.end());
    ok = false;
  }
  long double lo = 0, hi = 1e12, mid;
  while (hi - lo > 1e-7) {
    mid = (hi + lo) / 2;
    long double x = 0, y = 0;
    long double buff = mid;
    for (int i = 0; i < n; i++) {
      if (buff < taps[i].first) {
        x += buff * taps[i].second;
        y += buff;
        buff = 0;
      } else {
        x += taps[i].first * taps[i].second;
        y += taps[i].first;
        buff -= taps[i].first;
      }
    }
    if (buff > 0) {
      hi = mid;
      continue;
    }
    if (y) {
      x /= y;
    }
    if (ok) {
      if (x <= t) {
        lo = mid;
      } else {
        hi = mid;
      }
    } else {
      if (x >= t) {
        lo = mid;
      } else {
        hi = mid;
      }
    }
  }
  cout << (hi + lo) / 2;
  return 0;
}
