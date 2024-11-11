#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000009;
vector<pair<long long int, long long int> > wek;
long long int n, x, y, x2, y2, xBin, yBin, a, b;
string s;
double wynik, wynik2;
double obliczOdl(long long int x, long long int y, long long int x1,
                 long long int y1) {
  return sqrt(abs(x - x1) * abs(x - x1) + abs(y - y1) * abs(y - y1));
}
struct cmp {
  bool operator()(const pair<long long int, long long int> a,
                  const pair<long long int, long long int> b) const {
    double xc = obliczOdl(a.first, a.second, xBin, yBin);
    double xz = obliczOdl(b.first, b.second, xBin, yBin);
    double tmp = obliczOdl(a.first, a.second, x2, y2);
    double tmp2 = obliczOdl(b.first, b.second, x2, y2);
    if (tmp - xc == tmp2 - xz) return true;
    return xc - tmp > xz - tmp2;
  }
};
multiset<pair<long long int, long long int>, cmp> kolej;
int main() {
  scanf("%lld%lld%lld%lld%lld%lld", &x, &y, &x2, &y2, &xBin, &yBin);
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &a, &b);
    wek.push_back(pair<long long int, long long int>(a, b));
    wynik += 2LL * obliczOdl(xBin, yBin, wek[i].first, wek[i].second);
  }
  sort(wek.begin(), wek.end(), cmp());
  pair<long long int, long long int> best = wek[0];
  pair<long long int, long long int> best2;
  if (n > 1) best2 = wek[1];
  double maxWynik = (long long)maxN * 100000000;
  for (int i = 0; i < n; i++) {
    wynik += obliczOdl(wek[i].first, wek[i].second, x2, y2);
    wynik -= obliczOdl(xBin, yBin, wek[i].first, wek[i].second);
    maxWynik = min(maxWynik, wynik);
    wynik -= obliczOdl(wek[i].first, wek[i].second, x2, y2);
    wynik += obliczOdl(xBin, yBin, wek[i].first, wek[i].second);
  }
  for (int i = 0; i < n; i++) {
    wynik += obliczOdl(wek[i].first, wek[i].second, x, y);
    wynik -= obliczOdl(xBin, yBin, wek[i].first, wek[i].second);
    maxWynik = min(maxWynik, wynik);
    wynik -= obliczOdl(wek[i].first, wek[i].second, x, y);
    wynik += obliczOdl(xBin, yBin, wek[i].first, wek[i].second);
  }
  if (n != 1) {
    for (int i = 0; i < n; i++) {
      wynik += obliczOdl(wek[i].first, wek[i].second, x, y);
      wynik -= obliczOdl(xBin, yBin, wek[i].first, wek[i].second);
      maxWynik = min(maxWynik, wynik);
      if (wek[i].first == best.first && wek[i].second == best.second) {
        wynik += obliczOdl(best2.first, best2.second, x2, y2);
        wynik -= obliczOdl(best2.first, best2.second, xBin, yBin);
        maxWynik = min(maxWynik, wynik);
        wynik -= obliczOdl(best2.first, best2.second, x2, y2);
        wynik += obliczOdl(best2.first, best2.second, xBin, yBin);
      } else {
        wynik += obliczOdl(best.first, best.second, x2, y2);
        wynik -= obliczOdl(best.first, best.second, xBin, yBin);
        maxWynik = min(maxWynik, wynik);
        wynik -= obliczOdl(best.first, best.second, x2, y2);
        wynik += obliczOdl(best.first, best.second, xBin, yBin);
      }
      wynik -= obliczOdl(wek[i].first, wek[i].second, x, y);
      wynik += obliczOdl(xBin, yBin, wek[i].first, wek[i].second);
    }
  }
  printf("%.10f", maxWynik);
  return 0;
}
