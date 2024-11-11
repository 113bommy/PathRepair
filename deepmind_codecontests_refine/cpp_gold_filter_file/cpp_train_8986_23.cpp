#include <bits/stdc++.h>
using namespace std;
double prec = 0.00000001;
void calcHistory(vector<double>& history, int hp2, double p1, int l1, int h1) {
  double h[201];
  double newh[201];
  memset(h, 0, sizeof(h));
  memset(newh, 0, sizeof(newh));
  h[hp2] = 1.;
  for (int i = 0; i < history.size(); ++i) {
    for (int j = 1; j <= hp2; ++j)
      if (h[j] > 0) {
        double pHit = (1. - p1) / (h1 - l1 + 1.);
        for (int idx = l1; idx <= h1; ++idx) {
          int nIdx = j - idx > 0 ? j - idx : 0;
          newh[nIdx] += pHit * h[j];
        }
        newh[j] += p1 * h[j];
      }
    history[i] = newh[0];
    newh[0] = 0;
    for (int idx = 0; idx <= 200; ++idx)
      if (newh[idx] > prec)
        h[idx] = newh[idx];
      else
        h[idx] = 0.;
    memset(newh, 0, sizeof(newh));
  }
}
int main(int argc, char* argv[]) {
  stringstream strStr;
  int hp1;
  int dt1;
  int l1;
  int h1;
  int pp1;
  double p1;
  int hp2;
  int dt2;
  int l2;
  int h2;
  int pp2;
  double p2;
  cin >> hp1;
  cin >> dt1;
  cin >> l1;
  cin >> h1;
  cin >> pp1;
  cin >> hp2;
  cin >> dt2;
  cin >> l2;
  cin >> h2;
  cin >> pp2;
  strStr >> hp1;
  strStr >> dt1;
  strStr >> l1;
  strStr >> h1;
  strStr >> pp1;
  strStr >> hp2;
  strStr >> dt2;
  strStr >> l2;
  strStr >> h2;
  strStr >> pp2;
  p1 = double(pp1) / 100.;
  p2 = double(pp2) / 100.;
  vector<double> history(6000, 0.);
  calcHistory(history, hp2, p1, l1, h1);
  double res = 0;
  double h[201];
  double newh[201];
  memset(h, 0, sizeof(h));
  memset(newh, 0, sizeof(newh));
  h[hp1] = 1.;
  int k = 0;
  double p = 0.;
  double pp = 0.;
  for (int i = 0; i < history.size(); ++i) {
    double histP1 = history[i];
    while (dt2 * k < dt1 * i) {
      ++k;
      for (int j = 1; j <= hp1; ++j)
        if (h[j] > 0) {
          double pHit = (1. - p2) / (h2 - l2 + 1.);
          for (int idx = l2; idx <= h2; ++idx) {
            int nIdx = j - idx > 0 ? j - idx : 0;
            newh[nIdx] += pHit * h[j];
          }
          newh[j] += p2 * h[j];
        }
      pp += newh[0];
      for (int idx = 0; idx <= 200; ++idx)
        if (newh[idx] > prec)
          h[idx] = newh[idx];
        else
          h[idx] = 0.;
      memset(newh, 0, sizeof(newh));
    }
    res += histP1 * (1. - pp);
    p += histP1;
  }
  cout << showpoint << res;
  return 0;
}
