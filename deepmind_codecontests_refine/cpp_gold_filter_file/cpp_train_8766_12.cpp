#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x0, y0, ax, ay, bx, by, xs, ys, t;
  while (scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by) > 0) {
    long long xs, ys, t;
    scanf("%lld%lld%lld", &xs, &ys, &t);
    vector<long double> X, Y;
    X.push_back(x0);
    Y.push_back(y0);
    while (X.back() - xs <= t or Y.back() - ys <= t) {
      X.push_back(ax * X.back() + bx);
      Y.push_back(ay * Y.back() + by);
    }
    int ans = 0;
    for (int i = 0; i < X.size(); i++) {
      long double T = abs(xs - X[i]) + abs(ys - Y[i]);
      if (T > t) continue;
      int j = i - 1, cnt = 1;
      while (j >= 0) {
        T += abs(X[j] - X[j + 1]) + abs(Y[j] - Y[j + 1]);
        if (T <= t) {
          cnt++;
          j--;
        } else {
          break;
        }
      }
      ans = max(ans, cnt);
      T = abs(xs - X[i]) + abs(ys - Y[i]);
      j = i + 1;
      cnt = 1;
      while (j < X.size() and T <= t) {
        T += abs(X[j] - X[j - 1]) + abs(Y[j] - Y[j - 1]);
        if (T <= t) {
          cnt++;
          j++;
        } else {
          break;
        }
      }
      ans = max(ans, cnt);
    }
    printf("%d\n", ans);
  }
}
