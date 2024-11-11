#include <bits/stdc++.h>
using namespace std;
bool myfunction(int i, int j) { return (i < j); }
double n, a, d;
vector<pair<pair<double, double>, int> > ttv;
double tv[2][100001];
double ret[100001];
int main() {
  cin >> n >> a >> d;
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &tv[0][i], &tv[1][i]);
    ttv.push_back(make_pair(make_pair(tv[0][i], tv[1][i]), i));
  }
  sort(ttv.begin(), ttv.end());
  double t = ttv[0].first.second / a, bf;
  if (a * t * t / 2.0 > d)
    t = ttv[0].first.first + sqrt(d * 2.0 / a);
  else
    t = ttv[0].first.first + t + (d - (a * t * t / 2.0)) / ttv[0].first.second;
  ret[ttv[0].second] = t;
  bf = t;
  for (int i = 1; i < n; ++i) {
    double ti = ttv[i].first.first, v = ttv[i].first.second;
    t = v / a;
    if (a * t * t / 2.0 > d)
      t = ti + sqrt(d * 2.0 / a);
    else
      t = ti + t + (d - (a * t * t / 2.0)) / v;
    if (t >= bf)
      ret[ttv[i].second] = t;
    else
      ret[ttv[i].second] = bf;
    bf = t;
  }
  for (int i = 0; i < n; ++i) printf("%.10lf\n", ret[i]);
  return 0;
}
