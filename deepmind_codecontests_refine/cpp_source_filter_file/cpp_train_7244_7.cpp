#include <bits/stdc++.h>
using namespace std;
const int nmax = 250;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long sum = 0, sum2 = 0;
    long long maxx = 0;
    vector<long long> a;
    for (int i = 0; i < nmax; ++i) {
      long long x;
      cin >> x;
      a.push_back(x);
      maxx = max(maxx, x);
      sum += x;
      sum2 += x * x;
    }
    double mean = double(sum) / nmax;
    double disp =
        double(sum2) / nmax - (double(sum) / nmax) * (double(sum) / nmax);
    double sigma = sqrt(disp);
    if (maxx / sigma <= 2.1) {
      cout << "uniform\n";
    } else {
      cout << "poisson\n";
    }
  }
}
