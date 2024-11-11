#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
const int32_t mod = 1e9 + 7;
template <class T>
inline void smax(T &x, T y) {
  x = max((x), (y));
}
template <class T>
inline void smin(T &x, T y) {
  x = min((x), (y));
}
long long expo(long long x, long long n, long long mod) {
  long long res = 1LL;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n = n / 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, j, k;
  int n;
  string s, ss;
  int res = 0, x;
  cin >> n >> k;
  cin >> s;
  for (int i = (0); i < n; i++) {
    res += max(abs(s[i] - 'a'), abs(s[i] - 'z'));
  }
  i = 0;
  if (res < k) return cout << -1, 0;
  for (i = 0; i < n; i++) {
    x = max(abs(s[i] - 'a'), abs(s[i] - 'z'));
    if (s[i] <= 'm' && x <= k) {
      k -= ('z' - s[i]);
      ss += 'z';
    } else if (x <= k) {
      k -= abs('a' - s[i]);
      ss += 'a';
    } else
      break;
  }
  if (k) {
    if (s[i] + k <= 122)
      ss += s[i] + k;
    else
      ss += (s[i] - k);
    i++;
  }
  for (; i < n; i++) ss += s[i];
  cout << ss;
  return 0;
}
