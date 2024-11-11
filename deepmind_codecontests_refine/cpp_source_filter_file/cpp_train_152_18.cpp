#include <bits/stdc++.h>
using namespace std;
const int MX = 201020;
int N;
int ip[MX];
double ans = 1e9;
bool test(double x) {
  double minAns, minCur, maxAns, maxCur;
  minAns = maxAns = minCur = maxCur = 0.0;
  for (int i = 0; i < N; i++) {
    double t = ip[i] - x;
    minCur += t;
    maxCur += t;
    minCur = min(minCur, 0.0);
    maxCur = max(maxCur, 0.0);
    minAns = min(minAns, minCur);
    maxAns = max(maxAns, maxCur);
  }
  ans = min(ans, max(maxAns, -minAns));
  return maxAns >= (-minAns);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> ip[i];
  }
  double l = -10000, r = 10000;
  while (l < r - 1e-10) {
    double md = (l + r) / 2.0;
    if (test(md)) {
      l = md;
    } else {
      r = md;
    }
  }
  test((l + r) / 2);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
