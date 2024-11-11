#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const double eps = 1e-8;
int N;
long long K;
double pi;
int X[maxn], Y[maxn];
struct Seg {
  double radl, radr;
  void correct() {
    if (radl > 2 * pi) radl -= 2 * pi;
    if (radr > 2 * pi) radr -= 2 * pi;
    if (radl < 0) radl += 2 * pi;
    if (radr < 0) radr += 2 * pi;
    if (radl > radr) swap(radl, radr);
  }
  bool operator<(const Seg& rhs) const { return radl < rhs.radl; }
} ses[maxn];
double rads[maxn * 2];
unordered_map<double, int> mp;
int c[maxn * 2];
void add(int pos, int val) {
  while (pos <= N * 2) {
    c[pos] += val;
    pos += (pos & (-pos));
  }
}
int sum(int pos) {
  int res = 0;
  while (pos) {
    res += c[pos];
    pos -= (pos & (-pos));
  }
  return res;
}
int main() {
  scanf("%d%lld", &N, &K);
  long long ALL = 1ll * N * (N - 1) / 2;
  pi = acos(-1);
  for (int i = 1; i <= N; i++) scanf("%d%d", &X[i], &Y[i]);
  double mxr = 1e4, mir = 0;
  while (mxr - mir > eps) {
    double mid = (mxr + mir) / 2.0;
    int rcnt = 0, rscnt = 0;
    mp.clear();
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= N; i++) {
      double dis = sqrt(X[i] * X[i] + Y[i] * Y[i]);
      if (dis <= mid) continue;
      double ang = atan2(Y[i], X[i]) + pi;
      double dan = acos(mid / dis);
      ses[++rcnt] = Seg{ang + dan, ang - dan};
      ses[rcnt].correct();
      rads[++rscnt] = ses[rcnt].radl;
      rads[++rscnt] = ses[rcnt].radr;
    }
    sort(ses + 1, ses + rcnt + 1);
    sort(rads + 1, rads + rscnt + 1);
    for (int i = 1; i <= rscnt; i++) mp[rads[i]] = i;
    long long cnt = 0;
    for (int i = 1; i <= rcnt; i++) {
      cnt += sum(mp[ses[i].radr] - 1) - sum(mp[ses[i].radl]);
      add(mp[ses[i].radr], 1);
    }
    if (ALL - cnt >= K)
      mxr = mid;
    else
      mir = mid;
  }
  printf("%.8lf\n", mir);
  return 0;
}
