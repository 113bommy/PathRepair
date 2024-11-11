#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, mx, l, a[N], b[N], f[N];
bool check(int L) {
  if (L >= mx) return true;
  for (int d = 1; d <= 2; d++) {
    for (int i = 0; i <= n; i++) f[i] = 0;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      f[i] = max(f[i - 1], f[i]);
      if (i != d) {
        if (f[i - 1] >= a[i] - 1)
          f[i] = a[i] + L;
        else if (f[i - 1] + L < a[i] - 1)
          flag = false;
        else
          f[i] = max(f[i], a[i]);
        if (i < n && f[i - 1] + L >= a[i + 1] - 1) f[i + 1] = a[i] + L;
      } else {
        if (f[i - 1] + L < a[i] - 1)
          flag = false;
        else
          f[i] = max(a[i], max(f[i], f[i - 1]));
      }
    }
    if (f[n] + L + 1 - a[d] >= m) return true;
  }
  return false;
}
int main() {
  scanf("%d", &m);
  scanf("%d", &n);
  if (n == 1) {
    cout << m - 1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  mx = a[1] + m - a[n] - 1;
  for (int i = 1; i <= n - 1; i++) mx = max(a[i + 1] - a[i] - 1, mx);
  int mxa = 1;
  for (int i = 1; i <= n - 1; i++)
    if (a[i + 1] - a[i] - 1 == mx) mxa = i + 1;
  if (mxa) {
    l = 0;
    for (int i = mxa; i <= n; i++) b[++l] = a[i] - a[mxa] + 1;
    for (int i = 1; i <= mxa - 1; i++) b[++l] = a[i] + m - a[mxa] + 1;
    for (int i = 1; i <= n; i++) a[i] = b[i];
  }
  int L = 0;
  for (int j = 30; j >= 0; j--) L |= 1 << j, L ^= check(L) ? (1 << j) : 0;
  if (!check(L)) L++;
  printf("%d\n", L);
  return 0;
}
