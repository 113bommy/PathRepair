#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const long long LLINF = numeric_limits<long long>::max();
const unsigned long long ULLINF = numeric_limits<unsigned long long>::max();
const double PI = acos(-1.0);
int n;
long long a[255];
double sqr(double a) { return a * a; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    double mean = 0;
    double var = 0;
    for (int j = 0; j < 250; j++) {
      cin >> a[j];
      mean += a[j];
    }
    mean /= 250.0;
    for (int j = 0; j < 250; j++) var += sqr(a[j] - mean);
    var /= 249.0;
    if (abs(mean - var) / min(mean, var) < 0.2)
      cout << "poisson\n";
    else
      cout << "uniform\n";
  }
  return 0;
}
