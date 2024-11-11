#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long _x = 0;
  int _ch = getchar(), _f = 1;
  for (; !isdigit(_ch) && (_ch != '-') && (_ch != EOF); _ch = getchar())
    ;
  if (_ch == '-') {
    _f = 0;
    _ch = getchar();
  }
  for (; isdigit(_ch); _ch = getchar()) _x = _x * 10 + _ch - '0';
  return _f ? _x : -_x;
}
void write(long long _x) {
  if (_x >= 10)
    write(_x / 10), putchar(_x % 10 + '0');
  else
    putchar(_x + '0');
}
inline void wrt(long long _x, char _p) {
  if (_x < 0) putchar('-'), _x = -_x;
  write(_x);
  if (_p) putchar(_p);
}
int n;
int s1, s2;
int a[100005];
pair<int, int> H[100005];
set<int> st;
int dp[100005];
bool check(int len) {
  for (int i = int(1); i <= (int)(n); i++) dp[i] = n + 1;
  int pos = 0;
  st.clear(), st.insert(n + 1);
  for (int i = int(1); i <= (int)(n + 2); i++) {
    while (H[pos + 1].first < H[i].first - len)
      st.insert(H[pos + 1].second), pos++;
    dp[H[i].second] = *st.lower_bound(H[i].second > n ? 0 : H[i].second);
  }
  st.clear(), st.insert(n + 1);
  pos = n + 1;
  for (int i = int(n + 2); i >= (int)(1); i--) {
    while (H[pos - 1].first > H[i].first + len)
      st.insert(H[pos - 1].second), pos--;
    dp[H[i].second] = min(dp[H[i].second],
                          *st.lower_bound(H[i].second > n ? 0 : H[i].second));
  }
  int R = max(dp[n + 1], dp[n + 2]) - 1;
  for (int i = int(1); i <= (int)(n); i++) {
    if (R < i) return 0;
    R = max(R, dp[i] - 1);
  }
  return 1;
}
int main() {
  n = rd(), s1 = rd(), s2 = rd();
  for (int i = int(1); i <= (int)(n); i++)
    a[i] = rd(), H[i] = make_pair(a[i], i);
  H[n + 1] = make_pair(s1, n + 1);
  H[n + 2] = make_pair(s2, n + 2);
  sort(H + 1, H + 3 + n);
  int l = abs(s1 - s2), r = 1e9, ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  wrt(ans, '\n');
}
