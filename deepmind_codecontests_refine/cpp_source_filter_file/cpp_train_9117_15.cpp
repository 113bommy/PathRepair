#include <bits/stdc++.h>
using namespace std;
int main() {
  int v;
  cin >> v;
  while (v--) {
    int N = 250;
    double a[N];
    double mx = 0;
    for (int i = 0; i < N; i++) cin >> a[i];
    double mean = 0;
    double meanx2 = 0.0;
    for (int i = 0; i < N; i++)
      mean += a[i], meanx2 += a[i] * a[i], mx = max(mx, a[i]);
    mean /= N;
    meanx2 /= N;
    double varu = mean * (mean + 1) / 3;
    double varp = mean;
    double var = meanx2 - mean * mean;
    if (abs(varu - var) < abs(varp - var))
      cout << mx / 1.95 << endl;
    else
      cout << round(mean) << endl;
  }
}
