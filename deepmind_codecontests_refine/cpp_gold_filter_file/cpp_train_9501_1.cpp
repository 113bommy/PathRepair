#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
inline int rd() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void out(int a) {
  if (a < 0) putchar('-'), a = -a;
  if (a >= 10) out(a / 10);
  putchar(a % 10 + '0');
}
const int maxn = 2e5 + 10;
char s[maxn];
void solve() {
  int n = rd();
  scanf("%s", s + 1);
  char now = s[1];
  char check = s[n];
  int cnt = 0, pos = 1, ans = 0;
  if (now != check) {
    while (pos <= n) {
      cnt = 0;
      while (s[pos] == now && pos <= n) pos++, cnt++;
      ans += cnt / 3;
      now = s[pos];
    }
    cout << ans << '\n';
  } else {
    int l = 1, r = n;
    cnt = 0;
    while (s[l] == now && l <= r) l++, cnt++;
    while (s[r] == check && r >= l) r--, cnt++;
    ans += cnt / 3;
    if (l > r && (cnt) % 3 != 0) ans++;
    now = s[l];
    while (l <= r) {
      cnt = 0;
      while (s[l] == now) l++, cnt++;
      ans += cnt / 3;
      now = s[l];
    }
    cout << ans << '\n';
  }
}
int main() {
  for (int tt = rd(); tt--;) solve();
  return 0;
}
