#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const int maxn = 1010;
int N;
double X[maxn], Y[maxn];
int main() {
  cin >> N;
  if (N <= 4) return puts("No solution"), 0;
  double angle = 2.0 * acos(-1.0) / N;
  double now = 0, x = 0, y = 0;
  double L = 700, eps = 0.01;
  for (int i = 1; i <= N; i++) {
    X[i] = x + L * cos(now);
    Y[i] = y + L * sin(now);
    now += angle;
    L += eps;
    x = X[i];
    y = Y[i];
  }
  X[N] = X[N - 1] + (X[N] - X[N - 1]) * (Y[N - 1] / (Y[N - 1] - Y[N]));
  Y[N] = 0;
  for (int i = 1; i <= N; i++) printf("%.3f %.3f\n", X[i], Y[i]);
  return 0;
}
