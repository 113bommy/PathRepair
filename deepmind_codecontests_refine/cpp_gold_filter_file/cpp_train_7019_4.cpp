#include <bits/stdc++.h>
using namespace std;
struct data {
  int p, v;
};
int n, m;
int a[110000], b[110000];
data d[110000];
int f[110000];
long long ans[110000];
void add(int x, int y) {
  while (x <= n) {
    f[x] += y;
    x += (x & (-x));
  }
}
int quest(int x) {
  int ret = 0;
  while (x > 0) {
    ret += f[x];
    x -= (x & (-x));
  }
  return ret;
}
long long findleft(int le, int ri) {
  int rr = quest(ri), R = ri;
  long long mid, ans = ri;
  int c;
  while (le <= ri) {
    mid = (le + ri) / 2;
    c = rr - quest(mid - 1);
    if (c == R - mid + 1) {
      ans = mid;
      ri = mid - 1;
    } else {
      le = mid + 1;
    }
  }
  return ans;
}
long long findright(int le, int ri) {
  long long mid, ans = le;
  int c, lle = quest(le - 1), L = le;
  while (le <= ri) {
    mid = (le + ri) / 2;
    c = quest(mid) - lle;
    if (c == mid - L + 1) {
      ans = mid;
      le = mid + 1;
    } else {
      ri = mid - 1;
    }
  }
  return ans;
}
void solve(int x) {
  long long tmp = 0, c = 0;
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    if (a[i] & x) {
      b[i] = 1;
      add(i, 1);
      ++c;
      tmp += c;
    } else
      b[i] = c = 0;
  }
  long long le, ri;
  for (int i = 0; i < m; i++) {
    if (d[i].v & x) {
      if (b[d[i].p] == 0) {
        b[d[i].p] = 1;
        add(d[i].p, 1);
        le = findleft(1, d[i].p);
        ri = findright(d[i].p, n);
        tmp -= (d[i].p - le + 1) * (d[i].p - le) / 2;
        tmp -= (ri - d[i].p + 1) * (ri - d[i].p) / 2;
        tmp += (ri - le + 2) * (ri - le + 1) / 2;
      }
    } else {
      if (b[d[i].p] == 1) {
        le = findleft(1, d[i].p);
        ri = findright(d[i].p, n);
        tmp -= (ri - le + 2) * (ri - le + 1) / 2;
        tmp += (d[i].p - le + 1) * (d[i].p - le) / 2;
        tmp += (ri - d[i].p + 1) * (ri - d[i].p) / 2;
        b[d[i].p] = 0;
        add(d[i].p, -1);
      }
    }
    ans[i] += tmp * x;
  }
}
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d%d", &d[i].p, &d[i].v);
}
int main() {
  init();
  for (int i = 0; (1 << i) < 100000; i++) solve(1 << i);
  for (int i = 0; i < m; i++) cout << ans[i] << endl;
  return 0;
}
