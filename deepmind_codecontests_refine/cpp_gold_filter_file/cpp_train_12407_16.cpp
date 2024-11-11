#include <bits/stdc++.h>
using namespace std;
using LL = long long;
template <typename Container>
inline int ssize(Container& x) {
  return x.size();
}
int read() {
  register char c = '?';
  while (!isdigit(c)) c = getchar();
  register int ans = 0;
  for (; isdigit(c); c = getchar()) ans = ans * 10 + c - '0';
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  constexpr char endl = '\n';
  int n;
  char s[105];
  cin >> n >> &s[1];
  int a[105], b[105];
  for (register auto i = (1), __r = decltype(i)(n); i <= __r; ++i)
    cin >> a[i] >> b[i];
  int ans = count(&s[1], &s[n] + 1, '1');
  for (register auto t = (1), __r = decltype(t)(1e6); t <= __r; ++t) {
    for (register auto i = (1), __r = decltype(i)(n); i <= __r; ++i)
      if (t >= b[i] && (t - b[i]) % a[i] == 0) s[i] = '0' + '1' - s[i];
    ans = max(ans, (int)count(&s[1], &s[n] + 1, '1'));
  }
  cout << ans;
}
