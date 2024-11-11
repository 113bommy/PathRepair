#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int MAXN = 10000005;
const double eps = 1e-6;
int n, m, z;
long long a[1000000];
int cmd[500010], v[500010], l[500010], r[500010], t[500010], s[1000010],
    val[1000010];
map<int, int> time_idx, pre_time, ft;
int idx;
void add_t(int t) {
  if (time_idx.find(t) == time_idx.end()) {
    pre_time[idx] = t;
    time_idx[t] = idx++;
  }
}
void push_down(int node) {}
struct Info {
  long long s0;
  long long st;
  long long min_v;
  long long sp;
  long long start_time;
  long long end_time;
  int flag;
  Info() { flag = 0; }
} info[1000010];
Info merge(const Info &lt, const Info &rt) {
  Info cur;
  if (lt.flag && rt.flag) {
    int ed = lt.end_time;
    int sd = rt.start_time;
    long long ssp = lt.st + (sd - ed) * lt.sp;
    cur.s0 = lt.s0;
    cur.st = ssp + rt.st;
    cur.min_v = min(lt.min_v, min(ssp, rt.min_v + ssp));
    cur.sp = rt.sp;
    cur.start_time = lt.start_time;
    cur.end_time = rt.end_time;
    cur.flag = 1;
  } else if (lt.flag) {
    cur = lt;
  } else if (rt.flag) {
    cur = rt;
  }
  return cur;
}
void push_up(int node, int l, int r) {
  Info lt = info[node << 1], rt = info[node << 1 | 1];
  info[node] = merge(lt, rt);
}
void add(int node, int l, int r, int t_idx, int v, int flag) {
  if (l == r && l == t_idx) {
    val[r] = v;
    info[node].s0 = 0;
    info[node].st = 0;
    info[node].min_v = 0;
    info[node].sp = v;
    info[node].start_time = pre_time[l];
    info[node].end_time = pre_time[r];
    if (flag > 0) {
      info[node].flag = 1;
    } else {
      info[node].flag = 0;
    }
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= t_idx) {
    add(node << 1, l, mid, t_idx, v, flag);
  } else {
    add(node << 1 | 1, mid + 1, r, t_idx, v, flag);
  }
  push_up(node, l, r);
  Info cur = info[node];
}
Info query(int node, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) {
    return info[node];
  }
  if (ql > r || qr < l) {
    return Info();
  }
  int mid = (l + r) >> 1;
  if (qr <= mid) {
    return query(node << 1, l, mid, ql, qr);
  } else if (ql > mid) {
    return query(node << 1 | 1, mid + 1, r, ql, qr);
  }
  Info sum1 = query(node << 1, l, mid, ql, qr);
  Info sum2 = query(node << 1 | 1, mid + 1, r, ql, qr);
  return merge(sum1, sum2);
}
double cal(double start, double end, int v) {
  auto it1 = ft.lower_bound(start);
  auto it2 = ft.upper_bound(end);
  if (it2 != ft.begin()) {
    it2--;
    if (it1->second > it2->second) return 0;
    Info sum;
    if (it1->second != it2->second) {
      sum = query(1, 0, idx - 1, it1->second, it2->second);
    } else {
      sum.st = 0;
      sum.sp = val[it2->second];
      sum.end_time = it2->first;
      sum.start_time = it2->first;
      sum.min_v = 0;
    }
    double left_t = end - sum.end_time;
    double res = sum.st + sum.sp * left_t;
    double min_v = min((double)sum.min_v, res);
    return min_v;
  } else {
    return 0;
  }
}
void query(int start, int end, int v) {
  if (v == 0) {
    printf("%d\n", start);
    return;
  }
  auto it1 = ft.lower_bound(start);
  auto it2 = ft.lower_bound(end);
  if (it1 == it2) {
    printf("-1\n");
    return;
    if (it1 == ft.begin()) {
      printf("-1\n");
      return;
    } else {
      it1--;
      long long s = val[it1->second];
      long long sum = s * (end - start);
      double x = (double)v / s;
      if (start + x > end + eps) {
        printf("-1\n");
      } else {
        printf("%.6lf\n", start + x);
      }
      return;
    }
  }
  double l = start, r = end + eps;
  for (int i = 0; i < 46 && fabs(l - r) > eps; ++i) {
    double mid = (l + r) / 2.0;
    double sum = cal(start, mid, v);
    if (sum + v > eps) {
      l = mid;
    } else {
      r = mid;
    }
  }
  double t = cal(start, r, v);
  t += v;
  if (t > eps)
    printf("-1\n");
  else
    printf("%.6lf\n", r);
}
void sol() {
  for (int i = 0; i < n; ++i) {
    if (cmd[i] == 1) {
      add(1, 0, idx - 1, time_idx[t[i]], s[i], 1);
      ft[t[i]] = time_idx[t[i]];
    } else if (cmd[i] == 2) {
      add(1, 0, idx - 1, time_idx[t[i]], 0, 0);
      ft.erase(ft.find(t[i]));
    } else {
      query(l[i], r[i], v[i]);
    }
  }
}
int main() {
  idx = 0;
  scanf("%d", &n);
  vector<int> xxx;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &cmd[i]);
    if (cmd[i] == 1) {
      scanf("%d%d", &t[i], &s[i]);
      xxx.push_back(t[i]);
    } else if (cmd[i] == 2) {
      scanf("%d", &t[i]);
    } else if (cmd[i] == 3) {
      scanf("%d%d%d", &l[i], &r[i], &v[i]);
    }
  }
  sort(xxx.begin(), xxx.end());
  int pos = unique(xxx.begin(), xxx.end()) - xxx.begin();
  for (int i = 0; i < pos; ++i) {
    add_t(xxx[i]);
  }
  sol();
}
