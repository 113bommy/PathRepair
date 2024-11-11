#include <bits/stdc++.h>
using namespace std;
vector<pair<double, pair<double, double> > > pts;
double vp, vs;
pair<double, pair<double, double> > hp, pRes;
vector<double> distAcc;
double a2(double x) { return x * x; }
pair<double, pair<double, double> > posSnitch(double mid) {
  double xNew, x = mid * vs, dis;
  pair<double, pair<double, double> > npoint;
  int idx =
      lower_bound(distAcc.begin(), distAcc.end(), x) - distAcc.begin() - 1;
  dis = distAcc[idx + 1] - distAcc[idx];
  xNew = x - distAcc[idx];
  npoint = make_pair(
      ((pts[idx + 1].first - pts[idx].first) / dis * xNew),
      (make_pair(
          ((pts[idx + 1].second.first - pts[idx].second.first) / dis * xNew),
          ((pts[idx + 1].second.second - pts[idx].second.second) / dis *
           xNew))));
  npoint.first += pts[idx].first;
  npoint.second.first += pts[idx].second.first;
  npoint.second.second += pts[idx].second.second;
  return npoint;
}
double timeHarry(pair<double, pair<double, double> > pos) {
  return sqrt((a2(hp.first - pos.first) +
               a2(hp.second.first - pos.second.first) +
               a2(hp.second.second - pos.second.second))) /
         vp;
}
double bBinaria(double sup) {
  double inf = 0, mid, timeHP, res = -1;
  pair<double, pair<double, double> > posMid;
  while (fabs(sup - inf) * vs > 1e-10) {
    mid = (sup + inf) / 2;
    posMid = posSnitch(mid);
    timeHP = timeHarry(posMid);
    if ((timeHP - mid) > 1e-10) {
      inf = mid;
    } else {
      sup = mid;
      res = mid;
      pRes = posMid;
    }
  }
  return res;
}
int main() {
  int n;
  while (cin >> n) {
    double maxDist = 0, dist;
    distAcc = vector<double>(n + 1, 0);
    pts = vector<pair<double, pair<double, double> > >(n + 1);
    for (int i = 0; i <= n; i++) {
      cin >> pts[i].first >> pts[i].second.first >> pts[i].second.second;
      if (i > 0) {
        dist = sqrt(a2(pts[i].first - pts[i - 1].first) +
                    a2(pts[i].second.first - pts[i - 1].second.first) +
                    a2(pts[i].second.second - pts[i - 1].second.second));
        maxDist += dist;
        distAcc[i] = maxDist;
      }
    }
    cin >> vp >> vs;
    cin >> hp.first >> hp.second.first >> hp.second.second;
    double sol = bBinaria((maxDist + 1e-10) / vs);
    if (sol > -1) {
      cout << "YES" << endl;
      printf("%.7lf\n", sol);
      printf("%.7lf %.7lf %.7lf\n", pRes.first, pRes.second.first,
             pRes.second.second);
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
