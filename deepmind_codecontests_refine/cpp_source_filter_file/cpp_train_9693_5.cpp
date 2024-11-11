#include <bits/stdc++.h>
using namespace std;
const int Maxn = 200010;
int a[Maxn], b[Maxn << 1], bl;
int n, m;
int ans[Maxn], ansl;
int rad[Maxn << 1];
int _min(int x, int y) { return x < y ? x : y; }
int main() {
  int i, j, k;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  b[bl = 1] = -2;
  for (i = 1; i < n; i++) {
    b[++bl] = a[i + 1] - a[i];
    b[++bl] = -1;
  }
  b[bl] = -3;
  rad[1] = 1;
  k = 1;
  int mx = 2;
  for (i = 2; i < bl; i++) {
    if (i < mx)
      rad[i] = _min(rad[2 * k - i], mx - i);
    else
      rad[i] = 1;
    while (b[i - rad[i]] == b[i + rad[i]]) rad[i]++;
    if (i + rad[i] > mx) {
      mx = i + rad[i];
      k = i;
    }
  }
  if (rad[n - 1] >= n - 1) ans[++ansl] = (a[1] + a[n]) % m;
  for (i = 1; i < n; i++) {
    bool bk1 = false, bk2 = false;
    if (i == 1)
      bk1 = true;
    else if (rad[i - 1] >= i - 1)
      bk1 = true;
    if (i == n - 1)
      bk2 = true;
    else if (rad[i + n] >= n - i - 1)
      bk2 = true;
    if (bk1 == true && bk2 == true) {
      int p1 = a[1] + a[i], p2 = a[i + 1] + a[n] - m;
      if (p1 == p2) ans[++ansl] = a[1] + a[i];
    }
  }
  sort(ans + 1, ans + ansl + 1);
  printf("%d\n", ansl);
  for (i = 1; i <= ansl; i++) printf("%d%c", ans[i], " \n"[i == ansl]);
  return 0;
}
