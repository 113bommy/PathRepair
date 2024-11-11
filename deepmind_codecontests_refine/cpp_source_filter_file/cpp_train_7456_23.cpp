#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
int n, sum[1000050], p[1000050], ptot, f[1000050];
char s[1000050];
inline bool check(int l, int r) {
  return (l > r) || (sum[r] - sum[l - 1] <= 0);
}
inline bool check(int x) {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= ptot; i++) {
    if (check(f[i - 1] + 1, p[i] - x - 1)) f[i] = max(f[i], p[i]);
    if (check(f[i - 1] + 1, p[i] - 1)) f[i] = max(f[i], p[i] + x);
    if (i > 1 && check(f[i - 2] + 1, p[i] - x - 1))
      f[i] = max(f[i], p[i - 1] + x);
  }
  return check(f[ptot] + 1, n);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> (s + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (s[i] == '*');
    if (s[i] == 'P') p[++ptot] = i;
  }
  if (ptot == 1) {
    int p1 = sum[p[ptot]], p2 = sum[n] - sum[p[ptot]];
    int c1 = p[1] - 1, c2 = n - p[1], i = 1;
    while (p[i] == '.') {
      c1--;
      i++;
    }
    i = n;
    while (p[i] == '.') {
      c2--;
      i--;
    }
    if (p1 > p2 || (p1 == p2 && c1 < c2))
      cout << p1 << " " << c1 << endl;
    else
      cout << p2 << " " << c2 << endl;
    return 0;
  }
  cout << sum[n] << " ";
  int left = 1, right = n, ans = 0;
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (check(mid)) {
      ans = mid;
      right = mid - 1;
    } else
      left = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
