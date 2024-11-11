#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int MAXN = 400005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int a[MAXN], flag[MAXN], cnt[105];
vector<int> V;
signed main() {
  int n = read(), mx = 0, ans = 0;
  for (int i = 1; i <= n; i++) a[i] = read(), cnt[a[i]]++;
  for (int i = 1; i <= 100; i++) upmax(mx, cnt[i]);
  for (int i = 1; i <= 100; i++)
    if (mx == cnt[i]) V.push_back(i);
  if (V.size() > 1) {
    printf("%d\n", n);
    return 0;
  }
  for (int i = 1; i <= 100; i++) {
    if (i == V[0]) continue;
    for (int j = 0; j <= n + n; j++) flag[j] = n + n + 1;
    flag[n] = 0;
    for (int j = 1, num = n; j <= n; j++) {
      if (a[j] == V[0]) num--;
      if (a[j] == i) num++;
      if (flag[num] != n + n + 1)
        upmax(ans, j - flag[num]);
      else
        flag[num] = j;
    }
  }
  printf("%d\n", ans);
  return 0;
}
