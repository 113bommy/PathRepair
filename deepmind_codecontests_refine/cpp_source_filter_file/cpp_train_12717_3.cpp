#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[N], n, m, b[N];
int tomin(int now, int x) {
  if (now + x >= m)
    return 0;
  else
    return now;
}
bool check(int x) {
  b[1] = tomin(a[1], x);
  for (int i = 2; i <= n; i++) {
    if (a[i] + x < b[i - 1]) return false;
    if (a[i] + x == b[i - 1])
      b[i] = a[i] + x;
    else {
      if (a[i] <= b[i - 1])
        b[i] = b[i - 1];
      else if (a[i] + x >= m && (a[i] + x) % m >= b[i - 1])
        b[i] = b[i - 1];
      else
        b[i] = a[i];
    }
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = 0, r = n;
  while (l < r) {
    int mid = l + r >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", r);
  return 0;
}
