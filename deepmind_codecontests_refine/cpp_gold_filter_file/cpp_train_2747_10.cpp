#include <bits/stdc++.h>
using namespace std;
int X[100005], Xu, Yu;
double D[100005];
int n, k;
int lol;
void fuck() {
  sort(X, X + n + 1);
  for (int i = 0; i <= n; i++)
    if (X[i] == lol) {
      k = i;
      break;
    }
  double ans = X[n] - X[0] + min(X[k] - X[0], X[n] - X[k]);
  printf("%.8lf\n", ans);
  exit(0);
}
double f() {
  double ret = X[n - 1] - X[0] + D[n - 1];
  for (int l = 0; l < n - 1; l++) {
    int r1, r2;
    r2 = n - 1;
    r1 = max(k + 1, l + 1);
    double ans = (X[l] - X[0]) + D[l] +
                 (r1 > n - 1 ? 0 : ((X[r2] - X[r1]) + min(D[r2], D[r1])));
    ret = min(ret, ans);
  }
  return ret;
}
double g() {
  double ret = X[n - 1] - X[0] + D[0];
  for (int l = n - 1; l > 0; l--) {
    int r1 = 0;
    int r2 = min(k - 1, l - 1);
    double ans = (X[n - 1] - X[l]) + D[l] +
                 (r2 < 0 ? 0 : ((X[r2] - X[r1]) + min(D[r1], D[r2])));
    ret = min(ret, ans);
  }
  return ret;
}
double mid(int k) {
  if (k == 0) return D[k] + (X[n - 1] - X[1]) + min(D[1], D[n - 1]);
  if (k == n - 1) return D[k] + (X[n - 2] - X[0]) + min(D[0], D[n - 2]);
  return D[k] + (X[n - 1] - X[0]) + min(D[0], D[n - 1]);
}
double mm(int k) {
  double ret = mid(k);
  for (int l = 1; l < k; l++) {
    ret =
        min(ret, X[k] - X[l] + D[l] + (X[n - 1] - X[0]) + min(D[0], D[n - 1]));
    ret = min(ret, (X[k] - X[l]) + (X[n - 1] - X[l]) + D[n - 1] +
                       min(D[0], D[l - 1]) + (X[l - 1] - X[0]));
  }
  for (int l = k + 1; l < n - 1; l++) {
    ret =
        min(ret, X[l] - X[k] + D[l] + (X[n - 1] - X[0]) + min(D[0], D[n - 1]));
    ret = min(ret, X[l] - X[k] + (X[l] - X[0]) + D[0] +
                       min(D[n - 1], D[l + 1]) + (X[n - 1] - X[l + 1]));
  }
  ret = min(ret, X[k] - X[0] + f());
  ret = min(ret, X[n - 1] - X[k] + g());
  return ret;
}
int main() {
  cin >> n >> k;
  k--;
  for (int i = 0; i < n; i++) cin >> X[i];
  cin >> Xu >> Yu;
  X[n] = Xu;
  lol = X[k];
  if (Yu == 0) fuck();
  sort(X, X + n);
  for (int i = 0; i < n; i++)
    D[i] = sqrt(((long long)X[i] - Xu) * ((long long)X[i] - Xu) +
                ((long long)Yu * Yu));
  if (k == n) {
    double ans = min(D[0], D[n - 1]) + (X[n - 1] - X[0]);
    printf("%.8lf\n", ans);
    return 0;
  }
  for (int i = 0; i < n; i++)
    if (X[i] == lol) {
      k = i;
      break;
    }
  if (n == 1) {
    printf("%.8lf\n", D[0]);
    return 0;
  }
  double karan = mm(k);
  printf("%.8lf\n", karan);
  return 0;
}
