#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<long double, long double>, pair<long double, int> > > xvm;
bool funcion(
    const pair<pair<long double, long double>, pair<long double, int> > &par1,
    const pair<pair<long double, long double>, pair<long double, int> > &par2) {
  if (par1.first.first - par2.first.first > 1e-7) return false;
  if (par1.first.second - par2.first.second > 1e-7) return false;
  return true;
}
vector<long double> calc(long double t) {
  vector<long double> pos(xvm.size());
  int n = xvm.size();
  long double maxt = t;
  long double mint = 0;
  while (maxt - mint > 1e-11) {
    long double tm = (maxt + mint) / 2;
    for (int i = 0; i < (n); i++)
      pos[i] = xvm[i].first.first + tm * xvm[i].first.second;
    bool ord = true;
    for (int i = 0; i < (n - 1); i++)
      if (pos[i] >= pos[i + 1]) {
        ord = false;
        break;
      }
    if (ord == true)
      mint = tm;
    else
      maxt = tm;
  }
  vector<long double> speed(n);
  if (fabs(t - maxt) < 1e-8) {
    for (int i = 0; i < (xvm.size()); i++) xvm[i].first.first = pos[i];
    return pos;
  } else {
    for (int i = 0; i < (n); i++)
      pos[i] = xvm[i].first.first + maxt * xvm[i].first.second;
    for (int i = 0; i < (n); i++) {
      if (i != n - 1 && abs(pos[i] - pos[i + 1]) < 1e-7) {
        speed[i] = ((xvm[i].second.first - xvm[i + 1].second.first) *
                        xvm[i].first.second +
                    2 * xvm[i + 1].second.first * xvm[i + 1].first.second) /
                   (xvm[i].second.first + xvm[i + 1].second.first);
        speed[i + 1] = ((xvm[i + 1].second.first - xvm[i].second.first) *
                            xvm[i + 1].first.second +
                        2 * xvm[i].second.first * xvm[i].first.second) /
                       (xvm[i].second.first + xvm[i + 1].second.first);
        i++;
      } else
        speed[i] = xvm[i].first.second;
    }
  }
  for (int i = 0; i < (n); i++) {
    xvm[i].first.first = pos[i];
    xvm[i].first.second = speed[i];
  }
  sort(xvm.begin(), xvm.end(), funcion);
  return calc(t - maxt);
}
int main() {
  int n, t;
  cin >> n >> t;
  xvm.resize(n);
  for (int i = 0; i < (n); i++) {
    cin >> xvm[i].first.first >> xvm[i].first.second >> xvm[i].second.first;
    xvm[i].second.second = i;
  }
  sort(xvm.begin(), xvm.end());
  vector<long double> res = calc(t);
  for (int i = 0; i < (res.size()); i++)
    for (int j = 0; j < (res.size()); j++)
      if (xvm[j].second.second == i) {
        printf("%.6f\n", (double)xvm[j].first.first);
      }
}
