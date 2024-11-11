#include <bits/stdc++.h>
using namespace std;
int K, N;
long double XX, YY, P[101], PP, arr[101][101], obj[101][2], EPS = 1e-9;
double calk(int n, int k) {
  if (arr[n][k] != -1) return arr[n][k];
  double retAns = 0;
  if (n == 1 && k == 1)
    arr[n][k] = P[1];
  else if (n == 1 && k == 0)
    arr[n][k] = 1 - P[1];
  else if (n == 0 || k == 0 || k > n)
    arr[n][k] = 0;
  else {
    double v1 = calk(n - 1, k - 1) * P[n];
    double v2 = calk(n - 1, k) * (1 - P[n]);
    arr[n][k] = calk(n - 1, k - 1) * P[n] + calk(n - 1, k) * (1 - P[n]);
  }
  return arr[n][k];
}
double calcDist(double x, double y) {
  return (x - XX) * (x - XX) + (y - YY) * (y - YY);
}
double calk2(double r) {
  double retAns = 0;
  for (int i = 0; i <= N; i++) {
    for (int j = 0; j <= N; j++) arr[i][j] = -1;
    if (i) {
      double t = calcDist(obj[i][0], obj[i][1]);
      if (r * r > EPS && t > r * r)
        P[i] = exp(1.0 - t / (r * r));
      else
        P[i] = 1.0;
    }
  }
  int g;
  for (int k = K; k <= N; k++) retAns += calk(N, k);
  return retAns;
}
double binS(double l, double r) {
  if (fabs(l - r) < EPS) return l;
  double mid = l + (r - l) / 2.0;
  if (calk2(mid) > PP)
    return binS(l, mid);
  else
    return binS(mid, r);
}
int main() {
  cin >> N >> K;
  double tp;
  cin >> tp;
  tp /= 1000;
  tp = 1.0 - tp;
  PP = tp;
  cin >> XX >> YY;
  for (int i = 1; i <= N; i++) cin >> obj[i][0] >> obj[i][1];
  cout.setf(ios::fixed);
  cout.precision(10);
  cout << binS(0, 10000);
  return 0;
}
