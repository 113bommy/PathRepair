#include <bits/stdc++.h>
using namespace std;
int pre[200005], a[2 * 200005], b[3 * 200005];
int n, L;
bool ok(int val) {
  memset(pre, 0, sizeof(pre));
  int bas = n + 1, son = n;
  while (bas - 1 >= 1 && a[n + 1] - b[bas - 1] <= val) bas--;
  while (son + 1 <= 2 * n && b[son + 1] - a[n + 1] <= val) son++;
  for (int i = 1; i <= n; i++) {
    while (a[n + i] - b[bas] > val) bas++;
    while (son + 1 <= 3 * n && b[son + 1] - a[n + i] <= val) son++;
    int rl = n + i - bas;
    int rr = son - n - i;
    if (n - rl <= rr && rr >= 0 && rl > 0) {
      pre[0]++;
      pre[n]--;
    } else {
      if (rl > 0) {
        pre[max(0, n - rl)]++;
        pre[n]--;
      } else {
        pre[0]--;
        pre[min(n, -rl)]++;
      }
      if (rr >= 0) {
        pre[0]++;
        pre[min(n, rr + 1)]--;
      } else {
        pre[max(0, n + rr + 1)]--;
        pre[min(n, n + rr + 2)]++;
      }
    }
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += pre[i];
    if (cur == n) return true;
  }
  return false;
}
int main() {
  scanf("%d %d", &n, &L);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + n);
  for (int i = 1; i <= n; i++) {
    b[i + n] = b[i] + L;
    b[i + 2 * n] = b[i] + 2 * L;
    a[i + n] = a[i] + L;
  }
  int bas = 0, son = L;
  while (bas <= son) {
    if (ok(((bas + son) / 2)))
      son = ((bas + son) / 2) - 1;
    else
      bas = ((bas + son) / 2) + 1;
  }
  printf("%d", bas);
}
