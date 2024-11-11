#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
void gn(long long &x) {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  for (x = 0; c >= '0' && c <= '9';
       x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
}
int n;
int a[1111];
int star, dst;
int judge(int x) {
  for (int step = 0; step < 22222; step++) {
    int mx = -0x3f3f3f3f;
    int mn = 0x3f3f3f3f;
    int i;
    for (i = 0; i < n; i++) {
      smin(mn, a[i] + x - i * step);
      smax(mx, a[i] - x - i * step);
      if (mx > mn) break;
    }
    if (i == n) return star = mx, dst = step, 1;
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int st = -1;
  int ed = 0x3f3f3f3f;
  while (ed - st > 1) {
    int mid = (ed + st) / 2;
    if (judge(mid))
      ed = mid;
    else
      st = mid;
  }
  judge(ed);
  printf("%d\n", ed);
  printf("%d %d", star, dst);
  return 0;
}
