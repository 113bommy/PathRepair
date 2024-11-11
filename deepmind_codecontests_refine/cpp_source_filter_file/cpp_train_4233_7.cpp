#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-' && t != EOF; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  if (t == EOF) return false;
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
  return true;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
int power(int x, int y) {
  int ret = 1;
  do {
    if (y & 1) ret = 1ll * ret * x % mod;
    x = 1ll * x * x % mod;
  } while (y >>= 1);
  return ret;
}
inline void add(int &x, const int &y) {
  x += y;
  if (x >= mod) x -= mod;
}
int n, m, k, mxa[400111], mxb[400111];
pair<int, int> a[100111], b[100111];
int dp[2][400111];
int main() {
  (get_int(k) && (get_int(n) && get_int(m)));
  vector<int> v;
  v.push_back(0);
  v.push_back(k);
  for (int i = 1; i <= n; i++) {
    (get_int(a[i].first) && get_int(a[i].second));
    a[i].first--;
    v.push_back(a[i].first);
    v.push_back(a[i].second);
  }
  for (int i = 1; i <= m; i++) {
    (get_int(b[i].first) && get_int(b[i].second));
    b[i].first--;
    v.push_back(b[i].first);
    v.push_back(b[i].second);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  memset(mxa, -1, sizeof(mxa));
  memset(mxb, -1, sizeof(mxb));
  for (int i = 1; i <= n; i++) {
    a[i].first = lower_bound(v.begin(), v.end(), a[i].first) - v.begin();
    a[i].second = lower_bound(v.begin(), v.end(), a[i].second) - v.begin();
    mxa[a[i].second] = max(mxa[a[i].second], a[i].first);
  }
  for (int i = 1; i <= m; i++) {
    b[i].first = lower_bound(v.begin(), v.end(), b[i].first) - v.begin();
    b[i].second = lower_bound(v.begin(), v.end(), b[i].second) - v.begin();
    mxb[b[i].second] = max(mxa[b[i].second], b[i].first);
  }
  int cur[2] = {}, s[2] = {1, 0}, ts[2] = {};
  dp[0][0] = 1;
  for (int i = 0; i < (int)v.size() - 1; i++) {
    ts[0] = s[0];
    ts[1] = s[1];
    add(s[0], mod - dp[0][i]);
    add(s[0], mod - dp[0][i + 1]);
    add(s[1], mod - dp[1][i]);
    add(s[1], mod - dp[1][i + 1]);
    add(dp[0][i + 1],
        1ll * (ts[0] + ts[1]) * (power(2, v[i + 1] - v[i] - 1) - 1) % mod);
    add(dp[1][i + 1],
        1ll * (ts[0] + ts[1]) * (power(2, v[i + 1] - v[i] - 1) - 1) % mod);
    add(dp[0][i], ts[1]);
    add(dp[1][i], ts[0]);
    add(s[0], dp[0][i]);
    add(s[0], dp[0][i + 1]);
    add(s[1], dp[1][i]);
    add(s[1], dp[1][i + 1]);
    while (cur[0] <= mxa[i + 1]) add(s[0], mod - dp[0][cur[0]++]);
    while (cur[1] <= mxb[i + 1]) add(s[1], mod - dp[1][cur[1]++]);
  }
  int ans = 0;
  add(ans, s[0]);
  add(ans, s[1]);
  print_int(ans), puts("");
  return 0;
}
