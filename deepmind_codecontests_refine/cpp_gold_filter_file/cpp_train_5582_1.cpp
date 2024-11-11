#include <bits/stdc++.h>
using namespace std;
struct xxx {
  int id;
  long long x;
  bool operator<(const xxx &temp) const {
    if (x == temp.x) return id > temp.id;
    return x < temp.x;
  }
};
xxx xp[220000];
int cnt_x;
const int inf = 1e9 + 9;
int xx, yy;
struct point {
  int x, y, a, id;
  long long bs;
  bool operator<(const point &temp) const {
    if (abs((y - yy) * (temp.x - xx) - (x - xx) * (temp.y - yy)) == 0)
      return abs(x - xx) + abs(y - yy) > abs(temp.x - xx) + abs(temp.y - yy);
    return (y - yy) * (temp.x - xx) - (x - xx) * (temp.y - yy) < 0;
  }
};
point v[22000], fac[101000], pt[101000], vm[1 << 11];
int k, n, num_q, x[40004], cnt, x_list[101000], cx;
long long arr[101000], ans[101000];
bool cmp(point a, point b) { return a.bs < b.bs; }
int lower_bound(int left, int right, int x) {
  int mid;
  while (left <= right) {
    mid = (left + right) >> 1;
    if (x_list[mid] <= x)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return right;
}
int lowbit(int x) { return x & -x; }
int main() {
  scanf("%d%d%d", &k, &n, &num_q);
  int i, j, s, p, q, in = inf, ch, ip;
  for (i = 0; i < k; i++) {
    scanf("%d%d", &v[i].x, &v[i].y);
  }
  for (i = 0; i < (1 << k); i++) {
    vm[i].x = vm[i].y = 0;
    for (j = 0; j < k; j++) {
      if (i & (1 << j)) {
        vm[i].x += v[j].x;
        vm[i].y += v[j].y;
      } else {
        vm[i].x -= v[j].x;
        vm[i].y -= v[j].y;
      }
    }
  }
  in = inf;
  for (i = 0; i < (1 << k); i++) {
    if (in > vm[i].x) {
      in = vm[i].x;
      ch = i;
    }
  }
  swap(vm[0], vm[ch]);
  xx = vm[0].x;
  yy = vm[0].y;
  sort(vm + 1, vm + (1 << k));
  int nn = 0;
  for (i = 0; i < (1 << k); i++) {
    while (nn - 2 >= 0 &&
           (vm[nn - 1].y - vm[nn - 2].y) * (vm[i].x - vm[nn - 2].x) >=
               (vm[nn - 1].x - vm[nn - 2].x) * (vm[i].y - vm[nn - 2].y))
      nn--;
    vm[nn++] = vm[i];
  }
  k = nn;
  for (i = 0; i < nn; i++) v[i] = vm[i];
  in = inf;
  cnt = 0;
  for (i = 0; i < k; i++) x[cnt++] = v[i].x;
  sort(x, x + cnt);
  nn = 0;
  for (i = 0; i < cnt; i++) {
    if (nn == 0 || x[nn - 1] < x[i]) x[nn++] = x[i];
  }
  cnt = nn;
  for (i = 0; i < n; i++) scanf("%d%d%d", &fac[i].x, &fac[i].y, &fac[i].a);
  for (i = 0; i < num_q; i++) {
    scanf("%d%d%d", &pt[i].x, &pt[i].y, &pt[i].a);
    pt[i].id = i;
  }
  cx = 0;
  for (i = 0; i < n; i++) x_list[i] = fac[i].x;
  sort(x_list, x_list + n);
  for (i = 0; i < n; i++) {
    if (cx == 0 || x_list[cx - 1] < x_list[i]) x_list[cx++] = x_list[i];
  }
  memset(ans, 0, sizeof(ans));
  for (i = 0; i < cnt - 1; i++) {
    int id[2];
    memset(id, -1, sizeof(id));
    for (j = 0; j < k; j++) {
      if (min(v[j].x, v[(j + 1) % k].x) <= x[i] &&
          max(v[j].x, v[(j + 1) % k].x) >= x[i + 1]) {
        double mx, my[2];
        mx = 0.5 * (x[i] + x[i + 1]);
        my[0] = v[j].y + (mx - v[j].x) / (v[(j + 1) % k].x - v[j].x) *
                             (v[(j + 1) % k].y - v[j].y);
        if (id[0] < 0)
          id[0] = j;
        else {
          my[1] = v[id[0]].y + (mx - v[id[0]].x) /
                                   (v[(id[0] + 1) % k].x - v[id[0]].x) *
                                   (v[(id[0] + 1) % k].y - v[id[0]].y);
          if (my[0] < my[1]) id[0] = j;
        }
        if (id[1] < 0)
          id[1] = j;
        else {
          my[1] = v[id[1]].y + (mx - v[id[1]].x) /
                                   (v[(id[1] + 1) % k].x - v[id[1]].x) *
                                   (v[(id[1] + 1) % k].y - v[id[1]].y);
          if (my[0] > my[1]) id[1] = j;
        }
      }
    }
    int x1, y1, x2, y2;
    for (int ts = 0; ts < 2; ts++) {
      x1 = v[id[0]].x;
      y1 = v[id[0]].y;
      x2 = v[(id[0] + 1) % k].x;
      y2 = v[(id[0] + 1) % k].y;
      int flag = 1;
      if (ts == 1) {
        x1 = v[id[1]].x;
        y1 = v[id[1]].y;
        x2 = v[(id[1] + 1) % k].x;
        y2 = v[(id[1] + 1) % k].y;
        flag = -1;
      }
      if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
      }
      cnt_x = 0;
      for (j = 0; j < num_q; j++) {
        xp[cnt_x].id = j;
        xp[cnt_x++].x = 1LL * pt[j].y * (x2 - x1) - 1LL * pt[j].x * (y2 - y1) -
                        ts - (1LL * x2 * y1 - 1LL * x1 * y2) * pt[j].a;
      }
      for (j = 0; j < n; j++) {
        xp[cnt_x].id = j + num_q;
        xp[cnt_x++].x = 1LL * fac[j].y * (x2 - x1) - 1LL * fac[j].x * (y2 - y1);
      }
      sort(xp, xp + cnt_x);
      memset(arr, 0, sizeof(arr));
      for (j = 0; j < cnt_x; j++) {
        ip = xp[j].id;
        if (ip >= num_q) {
          for (s = lower_bound(0, cx - 1, fac[ip - num_q].x) + 1; s <= cx;
               s += lowbit(s))
            arr[s] += fac[ip - num_q].a;
        } else {
          int lx, rx;
          if (i + 1 == cnt - 1)
            lx = pt[ip].x - x[i + 1] * pt[ip].a - 1;
          else
            lx = pt[ip].x - x[i + 1] * pt[ip].a;
          rx = pt[ip].x - x[i] * pt[ip].a;
          for (s = lower_bound(0, cx - 1, rx) + 1; s > 0; s -= lowbit(s))
            ans[ip] += arr[s] * flag;
          for (s = lower_bound(0, cx - 1, lx) + 1; s > 0; s -= lowbit(s))
            ans[ip] -= arr[s] * flag;
        }
      }
    }
  }
  for (i = 0; i < num_q; i++) printf("%lld\n", ans[i]);
  return 0;
}
