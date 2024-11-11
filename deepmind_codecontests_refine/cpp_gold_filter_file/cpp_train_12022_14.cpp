#include <bits/stdc++.h>
using namespace std;
double lessThan(pair<int, int> inter, int val) {
  if (inter.first >= val) return 0.0;
  if (val > inter.second) return 1.0;
  return (val - inter.first + 0.0) / (inter.second - inter.first + 1.0);
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> distr(n);
  for (auto& d : distr) cin >> d.first >> d.second;
  const int MaxPrice = 10000;
  double ev = 0.0;
  vector<double> moreThan(MaxPrice + 2, 0.0);
  for (int p = 1; p <= MaxPrice; ++p) {
    double p1 = 1.0;
    double p2 = 1.0;
    for (int i = 0; i < n; ++i) p2 *= lessThan(distr[i], p);
    double p3 = 0.0;
    for (int j = 0; j < n; ++j) {
      double p4 = 1 - lessThan(distr[j], p);
      for (int i = 0; i < n; ++i) {
        if (i == j) continue;
        p4 *= lessThan(distr[i], p);
      }
      p3 += p4;
    }
    moreThan[p] = p1 - p2 - p3;
  }
  vector<double> exactly(MaxPrice + 1, 0.0);
  for (int p = 1; p <= MaxPrice; ++p)
    exactly[p] = moreThan[p] - moreThan[p + 1];
  for (int p = 1; p <= MaxPrice; ++p) ev += p * exactly[p];
  printf("%.12lf", ev);
  return 0;
}
