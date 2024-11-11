#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
vector<long long int> in;
long long int n, k;
long long int len;
bool func(long long int x) {
  long long int req = 1, p = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    if (in[i] > x) return false;
    if (p + in[i] <= x) {
      p += in[i];
    } else {
      p = 0;
      req++;
      i--;
    }
  }
  return req <= k;
}
long long int solve() {
  long long int l = 0, r = len;
  while (l + 1 < r) {
    long long int m = (l + r) / 2;
    if (func(m)) {
      r = m;
    } else
      l = m;
  }
  return r;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> k;
  getchar();
  string str;
  getline(cin, str);
  len = str.length();
  long long int s = 0;
  for (long long int i = 1; i <= len - 1; i++) {
    if (str[i] == ' ' or str[i] == '-') {
      in.emplace_back(i + 1 - s);
      s = i + 1;
    }
  }
  in.emplace_back(len - s);
  n = in.size();
  long long int ans = solve();
  cout << ans << '\n';
  return 0;
}
