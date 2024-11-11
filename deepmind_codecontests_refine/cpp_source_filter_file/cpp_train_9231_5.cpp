#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000 * 1000 * 1000;
const long long mod = INF + 7;
const double pi = 3.1415926535897932384626433832795;
const double eps = 0.000001;
const int p = 239;
int main() {
  int n, vb, vs;
  cin >> n >> vb >> vs;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  vector<double> t(n);
  int xu, yu;
  cin >> xu >> yu;
  t[0] = 0;
  for (int i = 1; i < n; ++i) t[i] = t[i - 1] + (x[i] - x[i - 1]) / (double)vb;
  double mn = INF;
  int imn = -1;
  for (int i = 1; i < n; ++i) {
    long long temp = (long long)(xu - x[i]) * (xu - x[i]) + yu * yu;
    double S = sqrt((double)temp);
    double tu = S / vs;
    if (tu + t[i] < mn) {
      mn = tu + t[i];
      imn = i;
    }
  }
  cout << imn + 1;
  return 0;
}
