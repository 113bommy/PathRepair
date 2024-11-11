#include <bits/stdc++.h>
using namespace std;
int N;
int t1[1010], x11[1010], y11[1010], t2[1010], x22[1010], y22[1010];
double x00[1010], y00[1010], vx[1010], vy[1010];
bool meet[1010][1010];
double t[1010][1010];
int most_freq(vector<double> &v) {
  int N = v.size();
  int i, j, ans = 0;
  sort(v.begin(), v.end());
  i = 0;
  while (i < N) {
    for (j = i; j < N; j++)
      if (v[j] - v[i] > 1.0E-9) break;
    ans = max(ans, j - i);
    i = j;
  }
  return ans;
}
int most_freq(vector<pair<double, double> > &v) {
  int N = v.size();
  int i, j, k, ans = 0;
  sort(v.begin(), v.end());
  i = 0;
  while (i < N) {
    for (j = i; j < N; j++)
      if (v[j].first - v[i].first > 1.0E-9) break;
    int tmp = 0;
    vector<double> w;
    for (k = i; k < j; k++) w.push_back(v[k].second);
    sort(w.begin(), w.end());
    for ((k) = 0; (k) < (int)(j - i); (k)++)
      if (k == 0 || w[k] - w[k - 1] > 1.0E-9) tmp++;
    ans = max(ans, tmp);
    i = j;
  }
  return ans;
}
int main(void) {
  int i, j;
  cin >> N;
  for ((i) = 0; (i) < (int)(N); (i)++)
    cin >> t1[i] >> x11[i] >> y11[i] >> t2[i] >> x22[i] >> y22[i];
  for ((i) = 0; (i) < (int)(N); (i)++) {
    vx[i] = (double)(x22[i] - x11[i]) / (t2[i] - t1[i]);
    vy[i] = (double)(y22[i] - y11[i]) / (t2[i] - t1[i]);
    x00[i] = x11[i] - vx[i] * t1[i];
    y00[i] = y11[i] - vy[i] * t1[i];
  }
  for ((i) = 0; (i) < (int)(N); (i)++)
    for ((j) = 0; (j) < (int)(i); (j)++) {
      double T = 0.0;
      if (((vx[i] - vx[j]) > 0 ? (vx[i] - vx[j]) : -(vx[i] - vx[j])) > 1.0E-9)
        T = (x00[i] - x00[j]) / (vx[j] - vx[i]);
      if (((vy[i] - vy[j]) > 0 ? (vy[i] - vy[j]) : -(vy[i] - vy[j])) > 1.0E-9)
        T = (y00[i] - y00[j]) / (vy[j] - vy[i]);
      if (((x00[i] + vx[i] * T - x00[j] - vx[j] * T) > 0
               ? (x00[i] + vx[i] * T - x00[j] - vx[j] * T)
               : -(x00[i] + vx[i] * T - x00[j] - vx[j] * T)) < 1.0E-9 &&
          ((y00[i] + vy[i] * T - y00[j] - vy[j] * T) > 0
               ? (y00[i] + vy[i] * T - y00[j] - vy[j] * T)
               : -(y00[i] + vy[i] * T - y00[j] - vy[j] * T)) < 1.0E-9) {
        meet[i][j] = meet[j][i] = true;
        t[i][j] = t[j][i] = T;
      }
    }
  int ans = 1;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    vector<double> times;
    for ((j) = 0; (j) < (int)(i); (j)++)
      if (meet[i][j]) times.push_back(t[i][j]);
    int tmp = most_freq(times);
    ans = max(ans, tmp + 1);
    vector<pair<double, double> > v;
    for ((j) = 0; (j) < (int)(i); (j)++)
      if (meet[i][j]) {
        double dx = vx[j] - vx[i], dy = vy[j] - vy[i];
        double arg = atan2(dy, dx);
        while (arg < 4.0) arg += acos(-1.0);
        double speed = cos(arg) * dx + sin(arg) * dy;
        v.push_back(make_pair(arg, speed));
      }
    tmp = most_freq(v);
    ans = max(ans, tmp + 1);
  }
  cout << ans << endl;
  return 0;
}
