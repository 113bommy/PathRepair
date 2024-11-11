#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long INF = 1e18;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
long long b[N], p[N], n, m, a;
bool check(long long x) {
  long long a1 = a;
  for (long long i = 0; i < x + 1; ++i) {
    if (b[x - i] < p[i]) {
      if (a1 >= p[i] - b[x - i])
        a1 -= p[i] - b[x - i];
      else
        return false;
    }
  }
  return true;
}
void solve() {
  cin >> n >> m >> a;
  for (long long i = 0; i < n; ++i) cin >> b[i];
  for (long long i = 0; i < m; ++i) cin >> p[i];
  sort(b, b + n, greater<long long>());
  sort(p, p + m);
  long long start = 0, end = min(n - 1, m - 1), ans = -1;
  while (start < end) {
    long long mid = (start + end + 1) / 2;
    if (check(mid))
      start = mid, ans = mid;
    else
      end = mid - 1;
  }
  cout << ans + 1 << " ";
  long long temp = 0;
  for (long long i = 0; i < ans + 1; ++i) {
    temp += p[i];
  }
  cout << max(temp - a, 0LL);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
