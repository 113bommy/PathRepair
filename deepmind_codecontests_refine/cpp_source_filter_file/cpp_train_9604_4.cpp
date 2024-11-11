#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int ans = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) ans = (ans << 3) + (ans << 1) + (c ^ 48);
  return ans * f;
}
inline int cmin(int &a, int b) { return a = min(a, b); }
inline int cmax(int &a, int b) { return a = max(a, b); }
int n;
int a[1000005], b[1000005], c[1000005];
int check(int mid) {
  for (int i = 1; i <= n; i++) c[i] = a[i];
  int lft = b[1] - mid;
  c[1] = a[1] - mid;
  for (int i = 2; i <= n; i++) {
    c[i] = max(c[i] - lft, 0);
    if (c[i] > b[i]) return 1;
    lft = b[i] - c[i];
    c[i] = 0;
  }
  if (c[1] > lft) return -1;
  return 0;
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) b[i] = read();
    int l = 0, r = min(a[1], b[1]), flag = 0;
    while (l < r) {
      int mid = l + r >> 1, ans = check(mid);
      if (ans == 0) {
        flag = 1;
        break;
      }
      if (ans < 0)
        l = mid + 1;
      else
        r = mid;
    }
    if (flag)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
