#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int ITER = 50;
const int LOG = 18;
const int INF = 1e9;
const long double eps = 1e-9;
int N, M;
pair<int, int> p[MAXN];
long double dist[MAXN], phi[MAXN];
int jmp[MAXN][LOG];
long double gap[MAXN][LOG];
long double pt[MAXN];
void load() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d%d", &p[i].first, &p[i].second);
}
bool check(long double r) {
  int least = -1;
  vector<pair<long double, int> > sweep;
  for (int i = 0; i < N; i++) {
    long double angle = acos(r / dist[i]);
    long double lo = phi[i] - angle;
    long double hi = phi[i] + angle;
    if (lo < 0) {
      lo += 2 * M_PI;
      hi += 2 * M_PI;
    }
    pt[2 * i] = lo;
    pt[2 * i + 1] = hi;
    for (auto it : {2 * i, 2 * i + 1}) sweep.push_back({pt[it], it});
    if (hi < 2 * M_PI && (least == -1 || hi < pt[least])) least = 2 * i + 1;
  }
  if (least == -1) return true;
  sort(sweep.begin(), sweep.end(), greater<pair<long double, int> >());
  long double opt = pt[least] + 2 * M_PI;
  for (auto it : sweep) {
    jmp[it.second][0] = least;
    gap[it.second][0] = opt - it.first;
    if (!(it.second % 2) && pt[it.second + 1] < opt) {
      opt = pt[it.second + 1];
      least = it.second + 1;
    }
  }
  for (int j = 1; j < LOG; j++)
    for (int i = 0; i < 2 * N; i++) {
      jmp[i][j] = jmp[jmp[i][j - 1]][j - 1];
      gap[i][j] = gap[i][j - 1] + gap[jmp[i][j - 1]][j - 1];
    }
  for (int i = 0; i < 2 * N; i++) {
    int x = i;
    long double trav = 0;
    for (int j = 0; j < LOG; j++)
      if (M >> j & 1) {
        trav += gap[x][j];
        x = jmp[x][j];
      }
    if (trav > 2 * M_PI - eps) return true;
  }
  return false;
}
long double solve() {
  sort(p, p + N);
  N = unique(p, p + N) - p;
  for (int i = 0; i < N; i++) {
    dist[i] = sqrt((long double)p[i].first * p[i].first +
                   (long double)p[i].second * p[i].second);
    phi[i] = atan2(p[i].second, p[i].first);
    if (phi[i] < 0) phi[i] += 2 * M_PI;
  }
  long double lo = 0, hi = *min_element(dist, dist + N);
  for (int i = 0; i < ITER; i++) {
    long double mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }
  return lo;
}
int main() {
  load();
  printf("%.10Lf\n", solve());
  return 0;
}
