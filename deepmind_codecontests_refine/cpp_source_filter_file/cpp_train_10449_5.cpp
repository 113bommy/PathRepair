#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
vector<int> sum[N << 2];
pair<int, int> p[N];
int num[10];
int x[N], y[N];
int n;
void build(int l, int r, int rt) {
  for (int i = l; i <= r; i++) {
    sum[rt].push_back(p[i].second);
  }
  sort(sum[rt].begin(), sum[rt].end());
  if (l == r) return;
  int mid = (r + l) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
}
int query(int L, int R, int top, int l, int r, int rt) {
  if (L <= l && R >= r) {
    int ret =
        upper_bound(sum[rt].begin(), sum[rt].end(), top) - sum[rt].begin();
    return ret;
  }
  int ret = 0;
  int mid = (r + l) >> 1;
  if (mid >= L) ret += query(L, R, top, l, mid, rt << 1);
  if (mid < R) ret += query(L, R, top, mid + 1, r, rt << 1 | 1);
  return ret;
}
bool check(int *a) {
  int x1 = a[0] + a[3] + a[6];
  int x2 = x1 + a[1] + a[4] + a[7];
  int y1 = a[0] + a[1] + a[2];
  int y2 = y1 + a[3] + a[4] + a[5];
  if (x1 + 1 > n || x[x1] == x[x1 + 1]) return false;
  if (x2 + 1 > n || x[x2] == x[x2 + 1]) return false;
  if (y1 + 1 > n || y[y1] == y[y1 + 1]) return false;
  if (y2 + 1 > n || y[y2] == y[y2 + 1]) return false;
  if (query(1, x1, y[y1], 1, n, 1) != a[0]) return false;
  if (query(1, x1, y[y2], 1, n, 1) != a[0] + a[3]) return false;
  if (query(x1 + 1, x2, y[y1], 1, n, 1) != a[1]) return false;
  if (query(x1 + 1, x2, y[y2], 1, n, 1) != a[1] + a[4]) return false;
  double ansx1 = (x[x1] + x[x2]) / 2.0, ansx2 = (x[x2] + x[x2 + 1]) / 2.0;
  double ansy1 = (y[y1] + y[y1 + 1]) / 2.0, ansy2 = (y[y2] + y[y2 + 1]) / 2.0;
  printf("%f %f %f %f\n", ansx1, ansx2, ansy1, ansy2);
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    p[i].first = a;
    p[i].second = b;
    x[i] = a;
    y[i] = b;
  }
  sort(p + 1, p + 1 + n);
  sort(x + 1, x + 1 + n);
  sort(y + 1, y + 1 + n);
  build(1, n, 1);
  for (int i = 0; i < 9; i++) scanf("%d", &num[i]);
  int cnt[10];
  for (int i = 0; i < 9; i++) cnt[i] = i;
  do {
    int now[10];
    for (int i = 0; i < 9; i++) {
      now[i] = num[cnt[i]];
    }
    if (check(now)) return 0;
  } while (next_permutation(cnt, cnt + 9));
  puts("-1");
  return 0;
}
