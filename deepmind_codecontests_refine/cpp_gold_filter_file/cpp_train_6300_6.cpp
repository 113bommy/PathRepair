#include <bits/stdc++.h>
using namespace std;
long double t[111];
long double t2[111];
const int MX = 1000000;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    t[i] /= 100;
    t2[i] = 1;
  }
  long double ans = 0;
  for (int i = 0; i < n; ++i) {
    t2[i] = 1 - t[i];
  }
  long double qwe = 1;
  for (int i = 0; i < n; ++i) {
    qwe *= t[i];
  }
  ans = n * qwe;
  for (int i = 1; i < MX; ++i) {
    pair<long double, int> best = {1, 0};
    for (int j = 0; j < n; ++j) {
      best = max(best, {(1 - (t2[j] * (1 - t[j]))) / (1 - t2[j]), j});
    }
    long double ed = 1;
    for (int j = 0; j < n; ++j) {
      ed *= 1 - t2[j];
    }
    long double nw = 1;
    t2[best.second] *= 1 - t[best.second];
    for (int j = 0; j < n; ++j) {
      nw *= 1 - t2[j];
    }
    ans += (nw - ed) * (i + n);
  }
  cout << fixed << setprecision(15) << ans << '\n';
}
