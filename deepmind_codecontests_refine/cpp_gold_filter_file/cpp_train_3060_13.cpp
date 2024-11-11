#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long ans;
int a[N], n, fuck;
void ask(int x, int y) {
  if (x > y) return;
  int l, r;
  if (y < a[n]) {
    l = 1, r = n;
    while (l < r) {
      int mid = (l + r) / 2;
      if (a[mid] <= y)
        l = mid + 1;
      else
        r = mid;
    }
  } else
    l = n + 1;
  int f = l - 1;
  if (x > a[0]) {
    l = 1, r = n;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (a[mid] >= x)
        r = mid - 1;
      else
        l = mid;
    }
  } else
    l = 0;
  int g = l + 1;
  if (f < g) return;
  ans += (f - g + 1);
}
int main() {
  int l, t;
  cin >> n >> l >> t;
  t *= 2;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int x = t / l;
  int y = t % l;
  ans = 1LL * x * (n - 1) * n * 2;
  for (int i = 1; i <= n; ++i) {
    fuck = i;
    x = a[i] - y;
    if (x >= 0) {
      ask(x, a[i] - 1);
    } else {
      ask(l + x, l - 1);
      ask(0, a[i] - 1);
    }
    x = a[i] + y;
    if (x < l) {
      ask(a[i] + 1, x);
    } else {
      ask(a[i] + 1, l - 1);
      ask(0, x - l);
    }
  }
  printf("%.8f\n", 1. * ans / 8);
  return 0;
}
