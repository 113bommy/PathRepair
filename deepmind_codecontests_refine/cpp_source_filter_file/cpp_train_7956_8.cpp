#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int c[N + N], pos[N], val[N + N];
bool have[N];
inline int lowbit(int x) { return x & (-x); }
int sum(int n) {
  int ret = 0;
  while (n > 0) {
    ret += c[n];
    n = n - lowbit(n);
  }
  return ret;
}
void update(int x, int v) {
  while (x < N + N) {
    c[x] += v;
    x += lowbit(x);
  }
}
int get_kth(int k, int l, int r) {
  int mid;
  while (l + 1 < r) {
    mid = (l + r) / 2;
    if (sum(mid) >= k)
      r = mid;
    else
      l = mid;
  }
  return r;
}
int main() {
  int n, m, x, y, score = 0;
  cin >> n >> m;
  bool f = true;
  for (int i = 1; i <= n; i++) {
    update(m + i, 1);
  }
  for (int t = 0; t < m; t++) {
    scanf("%d %d", &x, &y);
    if (f == false) {
      continue;
    }
    if (have[x] == false) {
      have[x] = true;
      int already = sum(m);
      if (y <= already) {
        f = false;
        continue;
      }
      int pre = get_kth(y, m, n + m);
      update(pre, -1);
      update(m - t, 1);
      pos[pre - m] = x;
    } else {
      int already = sum(m);
      if (y > already) {
        f = false;
        continue;
      }
      int pre = get_kth(y, 0, m);
      update(pre, -1);
      update(m - t, 1);
    }
  }
  if (f == false) {
    puts("-1");
    return 0;
  }
  int now = 1;
  for (int i = 1; i <= n; i++) {
    if (pos[i] == 0) {
      while (have[now] == true) {
        now++;
      }
      printf("%d ", now);
      now++;
    } else
      printf("%d ", pos[i]);
  }
}
