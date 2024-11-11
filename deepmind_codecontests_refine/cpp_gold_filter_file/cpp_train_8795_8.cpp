#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int a[N];
int n, x;
bool cmp(int x, int y) { return x > y; }
bool check(int add) {
  int y = x + add;
  for (int i = 1; i <= n; ++i) {
    if (a[i] >= y) {
      if (add <= 0) return false;
      add -= (a[i] - (y - 1));
      if (add < 0) return false;
    } else
      break;
  }
  return true;
}
int main(void) {
  scanf("%d", &n);
  scanf("%d", &x);
  n--;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n, cmp);
  if (x > a[1]) {
    puts("0");
    return 0;
  }
  int l = 0, r = 100000;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (l == 0) l++;
  printf("%d\n", l);
  return 0;
}
