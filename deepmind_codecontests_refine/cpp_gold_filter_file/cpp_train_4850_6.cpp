#include <bits/stdc++.h>
using namespace std;
int read() {
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while ('0' <= ch && ch <= '9') return ch - '0';
}
const int N = 200005;
int n, k, a[N], head, pos, l, r, ans, num;
bool check(int x) {
  head = pos = 1;
  num = 0;
  for (int i = 1; i < n; i++) {
    if (!a[i]) pos = i;
    if (i == head + x + 1) {
      if (pos == head) return 0;
      head = pos;
      num++;
    }
  }
  return num + 2 <= k;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) a[i] = read();
  l = 0;
  r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%d\n", ans);
  return 0;
}
