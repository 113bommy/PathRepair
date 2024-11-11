#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
pair<double, double> a[MAXN];
double F[MAXN], S[MAXN];
int n, p;
bool cmp(pair<double, double> x, pair<double, double> y) {
  return x.first * y.second > x.second * y.first;
}
int vt = -1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> p;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
  if (n == 1) {
    if (p >= a[1].first) {
      cout << -1;
      return 0;
    }
    double res = a[1].second / (a[1].first - p);
    cout << res;
    return 0;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) S[i] = S[i - 1] + a[i].second;
  for (int i = 1; i <= n; i++) F[i] = F[i - 1] + a[i].first;
  for (int i = 2; i <= n; i++) {
    double value = a[i].second / a[i].first;
    double res = value * F[i - 1] - S[i - 1];
    if (res > p * value) {
      vt = i;
      break;
    }
  }
  if (vt == -1) {
    double res = S[n] / (F[n] - p);
    if (res <= 0)
      cout << -1;
    else
      cout << res;
    return 0;
  }
  double kq = S[vt - 1] / (F[vt - 1] - p);
  cout << fixed;
  cout << setprecision(10) << kq;
  return 0;
}
