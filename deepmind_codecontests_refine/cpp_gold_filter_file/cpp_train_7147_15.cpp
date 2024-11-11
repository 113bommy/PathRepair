#include <bits/stdc++.h>
using namespace std;
int n, k, a[100005], ans, t[100005];
template <typename Drake>
void read(Drake &x) {
  x = 0;
  char ch = getchar();
  bool f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f ^= 1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x *= (2 * f - 1);
}
void init() {
  read(n);
  read(k);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(t[i]);
}
int main() {
  init();
  int Max = 0;
  ans = 0;
  for (int i = 1; i <= k; i++) ans += a[i];
  for (int i = k + 1; i <= n; i++) ans += a[i] * t[i];
  Max = ans;
  for (int l = 2; l <= n; l++) {
    int r = l + k - 1;
    if (!t[l - 1]) ans -= a[l - 1];
    if (r <= n && !t[r]) ans += a[r];
    Max = max(Max, ans);
  }
  cout << Max << endl;
  return 0;
}
