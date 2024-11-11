#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<double, int> x[200000];
double y, L, R;
int Ln, Rn, Cn;
double sqr(double z) { return z * z; }
double d(int a, int b) {
  if (x[a].second == n + 1 || x[b].second == n + 1)
    return sqrt(sqr(x[a].first - x[b].first) + y * y);
  return fabs(x[a].first - x[b].first);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(20);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x[i].first;
    x[i].second = i + 1;
  }
  cin >> x[n].first;
  cin >> y;
  x[n].second = n + 1;
  sort(x, x + n + 1);
  L = x[0].first;
  R = x[n].first;
  Ln = 0;
  Rn = n;
  if (x[n].second == n + 1) {
    Rn = n - 1;
    R = x[n - 1].first;
  }
  if (x[0].second == n + 1) {
    Ln = 1;
    L = x[1].first;
  }
  if (n == 1) {
    cout << d(0, 1) << endl;
    return 0;
  }
  for (int i = 0; i <= n; i++)
    if (x[i].second == n + 1) Cn = i;
  for (int i = 0; i <= n; i++)
    if (x[i].second == k) {
      k = i;
      break;
    }
  double ans = min(d(Cn, Ln), d(Cn, Rn)) + R - L + d(Cn, k);
  for (int i = 0; i <= n; i++)
    if (x[i].second != n + 1) {
      double t = d(k, i);
      int l, r;
      if (i == Ln || k == Ln)
        l = Ln;
      else
        l = min(k - 1, i - 1);
      if (x[l].second == n + 1) l--;
      if (i == Rn || k == Rn)
        r = Rn;
      else
        r = max(k + 1, i + 1);
      if (x[r].second == n + 1) r++;
      double l1 = d(Ln, i) + d(Ln, Cn) + R - x[r].first +
                  min(d(Cn, r), d(Cn, Rn)) * (i != Rn && k != Rn);
      double l2 = d(Rn, i) + d(Rn, Cn) + x[l].first - L +
                  min(d(Cn, l), d(Cn, Ln)) * (i != Ln && k != Ln);
      if (k == Ln) {
        double l3 =
            d(k, i) + R - x[r].first + min(d(Cn, r), d(Cn, Rn)) + d(Cn, i);
        ans = min(ans, l3);
      }
      if (k == Rn) {
        double l3 =
            d(k, i) + x[l].first - L + min(d(Cn, l), d(Cn, Ln)) + d(Cn, i);
        ans = min(ans, l3);
      }
      double l4 = d(Ln, k) + d(i, Ln) + d(i, Cn) + R - x[r].first +
                  min(d(Cn, r), d(Cn, Rn)) * (i != Rn && k != Rn);
      double l5 = d(Rn, k) + d(i, Rn) + d(i, Cn) + x[l].first - L +
                  min(d(Cn, l), d(Cn, Ln)) * (i != Ln && k != Ln);
      ans = min(ans, t + min(l1, l2));
      ans = min(ans, min(l4, l5));
    }
  if (k == Cn) ans = R - L + min(d(Cn, Ln), d(Cn, Rn));
  cout << ans;
}
