#include <bits/stdc++.h>
using namespace std;
inline int Get() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
int x[100005], y[100005];
long long dx = 1;
int cnt[100005];
int ans = 2;
map<int, int> num;
map<int, int>::iterator it;
void solve() {
  long long q = 2 * dx;
  if (!q) q = -1 << 30;
  for (int i = 1; i <= n; i++) num[x[i] % q]++;
  for (int i = 1; i <= m; i++) num[(y[i] + dx) % q]++;
  for (it = num.begin(); it != num.end(); it++) ans = max(ans, it->second);
  num.clear();
}
int main() {
  n = Get(), Get();
  for (int i = 1; i <= n; i++) x[i] = Get();
  m = Get(), Get();
  for (int i = 1; i <= m; i++) y[i] = Get();
  while (dx <= 1e9) {
    solve();
    dx <<= 1;
  }
  cout << ans;
  return 0;
}
