#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + c - '0';
  x *= f;
}
int n, L;
long long a[N], b[N << 1];
int l[N], r[N];
int q[N], head, tail;
bool check(int delta) {
  int lpos = 1, rpos = 1;
  head = 1, tail = 0;
  for (int i = 1; i <= 2 * n; i++) {
    while (lpos <= 4 * n && b[lpos] < a[i] - delta) lpos++;
    while (rpos <= 4 * n && b[rpos] <= a[i] + delta) rpos++;
    l[i] = lpos, r[i] = rpos - 1;
    if (l[i] > r[i]) return false;
    while (head <= tail && q[head] <= i - n) head++;
    while (head <= tail && l[q[tail]] - q[tail] < l[i] - i) tail--;
    q[++tail] = i;
    if (r[i] - i < l[q[head]] - q[head]) return false;
  }
  return true;
}
int main() {
  read(n), read(L);
  for (int i = 1; i <= n; i++) read(a[i]);
  for (int i = 1; i <= n; i++) read(b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) a[i] += L, a[i + n] = a[i] + L;
  for (int i = 1; i <= 3 * n; i++) b[i + n] = b[i] + L;
  int l = 0, r = L, ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
