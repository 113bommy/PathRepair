#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
const long long INF = 1e18;
void dprint(string s) { cout << "\n"; }
void dprint() { cout << "\n"; }
template <class T, class... U>
void dprint(string s, T t, U... u) {
  long long w = s.find(',');
  cout << "[" << s.substr(0, w) << ": " << t << "] ";
  dprint(s.substr(w + 1, (long long)(s).size() - w), u...);
}
const long long N = 100005;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  if (n * (n - 1) / 2 <= k) return cout << "No solution", 0;
  long long x = 1, y = 1;
  for (long long i = 1; i <= n; i++) {
    cout << x << ' ' << i << "\n";
  }
  return 0;
}
