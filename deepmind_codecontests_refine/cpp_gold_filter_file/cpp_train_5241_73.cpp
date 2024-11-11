#include <bits/stdc++.h>
using namespace std;
const int di[4] = {0, 1, 0, -1};
const int dj[4] = {1, 0, -1, 0};
const int P = 1;
int N;
int A[2010][2010];
int K;
int B[2010][2010];
bool vis[2010][2010];
vector<pair<int, int> > ps;
void search(int i, int j) {
  queue<pair<int, int> > que;
  que.push(make_pair(i, j));
  vis[i][j] = true;
  while (!que.empty()) {
    i = que.front().first;
    j = que.front().second;
    que.pop();
    ps.push_back(make_pair(i, j));
    for (int d = 0; d < (int)(4); d++) {
      int ti = i + di[d];
      int tj = j + dj[d];
      if (ti < 0 || K <= ti || tj < 0 || K <= tj) continue;
      if (!B[ti][tj]) continue;
      if (vis[ti][tj]) continue;
      vis[ti][tj] = true;
      que.push(make_pair(ti, tj));
    }
  }
}
double relerror(double x, double y) {
  return fabs(y - x) / max(fabs(y), fabs(x));
}
int square, circle;
double avg(vector<int> a) {
  return accumulate((a).begin(), (a).end(), 0.0) / a.size();
}
inline int getA(int y, int x) {
  if (y < 0 || N <= y || x < 0 || N <= x)
    return 0;
  else
    return A[y][x];
}
void doit(int i, int j) {
  ps.clear();
  search(i, j);
  if (ps.size() <= 3) return;
  int imax = INT_MIN, imin = INT_MAX, jmax = INT_MIN, jmin = INT_MAX;
  for (int k = 0; k < (int)(ps.size()); k++) {
    imax = max(imax, ps[k].first);
    imin = min(imin, ps[k].first);
    jmax = max(jmax, ps[k].second);
    jmin = min(jmin, ps[k].second);
  }
  vector<int> imax_js, imin_js, jmax_is, jmin_is;
  for (int k = 0; k < (int)(ps.size()); k++) {
    if (ps[k].first == imax) imax_js.push_back(ps[k].second);
    if (ps[k].first == imin) imin_js.push_back(ps[k].second);
    if (ps[k].second == jmax) jmax_is.push_back(ps[k].first);
    if (ps[k].second == jmin) jmin_is.push_back(ps[k].first);
  }
  double imax_javg = avg(imax_js);
  double imin_javg = avg(imin_js);
  double jmax_iavg = avg(jmax_is);
  double jmin_iavg = avg(jmin_is);
  int area = 0;
  for (int y = imin * P; y < min(N, imax * P); ++y) {
    for (int x = jmin * P; x < min(N, jmax * P); ++x) {
      area += A[y][x];
    }
  }
  double h = (imax - imin) * P + P;
  double w = (jmax - jmin) * P + P;
  double r = (h + w) / 2.0 / 2.0;
  int y = round(((imin + P / 2.0) + (imax - imin) / 2.0) * P);
  int x = round(((jmin + P / 2.0) + (jmax - jmin) / 2.0) * P);
  const int D = 20;
  for (int dy = -D; dy <= D; dy += 3) {
    int ty = y + dy;
    for (int dx = -D; dx <= D; dx += 3) {
      int tx = x + dx;
      for (int dr = -D; dr <= D; dr += 3) {
        int tr = r + dr;
        if (tr < 5) continue;
        const int S = 100;
        int in = 0, ou = 0;
        for (int i = 0; i < (int)(S); i++) {
          double a = M_PI * 2 * i / S;
          double sa = sin(a);
          double ca = cos(a);
          in += getA(round(ty + tr * 0.88 * sa), round(tx + tr * 0.88 * ca));
          ou += getA(round(ty + tr * 1.12 * sa), round(tx + tr * 1.12 * ca));
        }
        if (in / double(S) > 0.9 && ou / double(S) < 0.1) {
          ++circle;
          return;
        } else {
        }
      }
    }
  }
  ++square;
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < (int)(N); i++)
    for (int j = 0; j < (int)(N); j++) scanf("%d", &A[i][j]);
  K = N / P;
  for (int i = 0; i < (int)(N); i++)
    for (int j = 0; j < (int)(N); j++) B[i / P][j / P] += A[i][j];
  for (int i = 0; i < (int)(K); i++)
    for (int j = 0; j < (int)(K); j++) {
      if (B[i][j] > 0.6 * P * P)
        B[i][j] = 1;
      else
        B[i][j] = 0;
    }
  for (int i = 0; i < (int)(K); i++)
    for (int j = 0; j < (int)(K); j++) {
      if (B[i][j] && !vis[i][j]) {
        doit(i, j);
      }
    }
  printf("%d %d\n", circle, square);
  return 0;
}
