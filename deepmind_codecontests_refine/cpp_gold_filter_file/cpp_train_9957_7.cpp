#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
int n, k;
int d[MAXN];
vector<int> a[MAXN];
bool flg[MAXN];
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
inline long long f(int n) {
  long long ret = 0;
  for (int i = 1; i <= n; i++) ret += 1LL * n / i - 1;
  return ret;
}
int main() {
  read(n);
  read(k);
  if (k > f(n)) {
    printf("No\n");
    return 0;
  }
  while (f(n >> 1) >= k) n >>= 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      ++d[j];
    }
  }
  for (int i = n / 2 + 1; i <= n; i++) a[d[i]].push_back(i);
  memset(flg, true, sizeof(flg));
  int m = f(n) - k;
  for (int i = n; i >= 1; i--) {
    for (unsigned j = 0; j < (int)a[i].size(); j++) {
      if (m >= i) {
        m -= i;
        flg[a[i][j]] = false;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (flg[i]) ans++;
  printf("Yes\n%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (flg[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
