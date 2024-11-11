#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
const long long mod = 998244353;
const long double Exp = 1e-12;
const bool debug = false;
struct M {
  long double v[3][3];
  int n;
  void init(long double p) {
    n = 3;
    v[0][0] = 1 - p;
    v[1][0] = p;
    v[1][1] = v[2][1] = v[2][2] = 1;
  }
  M operator*(M &it) const {
    M ret;
    ret.n = n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ret.v[i][j] = 0.0;
        for (int k = 0; k < n; ++k) {
          ret.v[i][j] += v[i][k] * it.v[k][j];
        }
      }
    }
    return ret;
  }
} tp[40];
pair<long double, long double> node[N];
int line[N], en;
bool cmp(int k, int j, int i) {
  if (node[i].first - node[j].first < Exp) return true;
  return (node[j].first - node[k].first) * (node[j].second - node[i].second) <
         (node[i].first - node[j].first) * (node[k].second - node[j].second);
}
bool cmp2(int i, int j, long double x) {
  return x * (node[i].first - node[j].first) > node[j].second - node[i].second;
}
int main() {
  int n;
  long long t;
  scanf("%d%lld", &n, &t);
  long double mx = 0, ans = 0;
  for (int i = 1; i <= n; ++i) {
    int a, b;
    double p;
    scanf("%d%d%lf", &a, &b, &p);
    node[i] = {p, p * a};
    mx = max(mx, (long double)p * b);
  }
  sort(node + 1, node + n + 1);
  en = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, t * node[i].second);
    while (en >= 2 && cmp(line[en - 1], line[en], i)) en--;
    while (en && node[i].first - node[line[en]].first < Exp) en--;
    line[++en] = i;
  }
  long double now = 0;
  long long now_t = 0;
  for (int i = 1, id, iid; i < en; ++i) {
    id = line[i], iid = line[i + 1];
    if (debug) {
      cout << i << " : " << node[id].first << " " << node[id].second << endl;
      cout << now << " " << now_t << endl;
      cout << (node[id].second - node[iid].second) /
                  (node[iid].first - node[id].first)
           << endl;
    }
    tp[0].init(node[id].first);
    for (int j = 1; j < 40; ++j) tp[j] = tp[j - 1] * tp[j - 1];
    for (int j = 35; j >= 0; --j) {
      if (now_t + (1ll << j) > t) continue;
      long long to_t = now_t + (1ll << j);
      long double to =
          tp[j].v[0][0] * now +
          tp[j].v[1][0] * (node[id].second / node[id].first + now_t * mx) +
          tp[j].v[2][0] * mx;
      if (!cmp2(iid, id, to_t * mx - to)) now = to, now_t = to_t;
    }
    if (!cmp2(iid, id, now_t * mx - now) && now_t < t)
      now = tp[0].v[0][0] * now +
            tp[0].v[1][0] * (node[id].second / node[id].first + now_t * mx),
      now_t++;
    if (debug) {
      cout << now << " " << now_t << endl;
    }
  }
  en = line[en];
  if (debug) {
    cout << now_t << endl;
    cout << en << " : " << node[en].first << " " << node[en].second << endl;
  }
  tp[0].init(node[en].first);
  for (int j = 1; j < 40; ++j) tp[j] = tp[j - 1] * tp[j - 1];
  for (int j = 35; j >= 0; --j) {
    if (now_t + (1ll << j) > t) continue;
    now = tp[j].v[0][0] * now +
          tp[j].v[1][0] * (node[en].second / node[en].first + now_t * mx) +
          tp[j].v[2][0] * mx;
    now_t += (1ll << j);
  }
  ans = max(ans, now);
  printf("%.12Lf\n", ans);
  return 0;
}
