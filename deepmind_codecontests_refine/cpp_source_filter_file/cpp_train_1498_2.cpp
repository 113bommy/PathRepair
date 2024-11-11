#include <bits/stdc++.h>
using namespace std;
const double INF = 1e18;
const int MUL = 1000 * 1000;
const int MAXN = 1000 + 2;
const int MAXT = 1600 + 10;
struct Prob {
  int ts, tl, ss, sl;
  long long s1, s2;
  double fail;
  double rate;
} p[MAXN + 10];
bool cmp(Prob a, Prob b) { return a.rate < b.rate; }
pair<long long, double> d[MAXN + 10][MAXT + 10];
int n, t;
void output();
void input();
void dyn();
int main() {
  input();
  sort(p, p + n, cmp);
  dyn();
  output();
  return 0;
}
void output() {
  int best = 0;
  for (int i = 1; i <= t; i++)
    if (d[n][i].first > d[n][best].first ||
        (d[n][i].first == d[n][best].first &&
         d[n][i].second < d[n][best].second))
      best = i;
  cout << setprecision(6) << fixed << (double)d[n][best].first / MUL << " "
       << d[n][best].second << endl;
}
inline void update(int i, int j, pair<long long, double> inp) {
  if (j <= t)
    if (d[i][j].first < inp.first ||
        (d[i][j].first == inp.first && d[i][j].second > inp.second))
      d[i][j] = inp;
}
void dyn() {
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= t; j++) d[i][j].first = -1;
  d[0][0].first = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= t; j++) {
      update(i + 1, j, d[i][j]);
      update(i + 1, j + p[i].ts,
             pair<long long, double>(d[i][j].first + p[i].s1,
                                     d[i][j].second + p[i].ts));
      update(
          i + 1, j + p[i].ts + p[i].tl,
          pair<long long, double>(d[i][j].first + p[i].s1 + p[i].s2,
                                  (p[i].ts + j + p[i].tl) * (1.0 - p[i].fail) +
                                      (p[i].ts + d[i][j].second) * p[i].fail));
    }
}
void input() {
  ios::sync_with_stdio(false);
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> p[i].ss >> p[i].sl >> p[i].ts >> p[i].tl >> p[i].fail;
    int tmp = (int)(p[i].fail * MUL + 0.5);
    p[i].rate = (tmp == MUL ? INF : p[i].tl * p[i].fail / (1.0 - p[i].fail));
    p[i].s1 = (long long)p[i].ss * (long long)MUL;
    p[i].s2 = (long long)p[i].sl * ((long long)MUL - tmp);
  }
}
