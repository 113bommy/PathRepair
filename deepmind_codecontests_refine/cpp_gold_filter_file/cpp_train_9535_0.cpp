#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n, a[N], as[2], ans, mx;
inline void read(int &i) {
  i = 0;
  char c = getchar();
  bool j = 0;
  for (; !isdigit(c); c = getchar())
    if (c == '-') j = 1;
  for (; isdigit(c); c = getchar()) i = (i << 1) + (i << 3) + c - '0';
  i = j ? -i : i;
}
inline int f(int i, int o) {
  if (!o) return max(a[i], a[i + 1]);
  if (a[i] >= a[i - 1] && a[i] >= a[i + 1]) return max(a[i - 1], a[i + 1]);
  return a[i];
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]), mx = max(mx, a[i]);
  int l = (n + 1) / 2, r = l;
  for (int i = 0; i < n - 1; ++i) {
    ans = f(l, (n - i) & 1);
    ans = max(ans, f(r, (n - i) & 1));
    ans = max(ans, as[(n - i) & 1]);
    as[(n - i) & 1] = max(as[(n - i) & 1], ans);
    if ((n - i) & 1)
      l--;
    else
      r++;
    printf("%d ", ans);
  }
  printf("%d ", mx);
  return 0;
}
