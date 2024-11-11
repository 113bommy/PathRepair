#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int n;
int x[maxN], y[maxN];
long long k;
long double ang[maxN];
const long double pi = acosl(-1.0);
long double norm(long double x) {
  while (x < 0) x += 2 * pi;
  while (x >= 2 * pi) x -= 2 * pi;
  return x;
}
struct Fenwick {
  vector<int> f;
  int n;
  Fenwick(int _n) {
    n = _n;
    f.resize(_n + 1);
  }
  void upd(int pos, int v) {
    while (pos <= n) {
      f[pos] += v;
      pos = (pos | (pos - 1)) + 1;
    }
  }
  int get(int r) {
    long long ans = 0;
    while (r > 0) {
      ans += f[r];
      r &= (r - 1);
    }
    return ans;
  }
  int get(int l, int r) { return get(r) - get(l - 1); }
};
long long calc(long double R) {
  vector<pair<long double, long double>> segs;
  vector<long double> cord;
  for (int i = 1; i <= n; i++) {
    long double dist =
        sqrt((long double)x[i] * x[i] + (long double)y[i] * y[i]);
    if (dist <= R) continue;
    long double angs = acosl(R / dist);
    long double f1 = norm(ang[i] - angs);
    long double f2 = norm(ang[i] + angs);
    if (f1 > f2) swap(f1, f2);
    segs.emplace_back(f1, f2);
    cord.emplace_back(f1);
    cord.emplace_back(f2);
  }
  if (cord.empty()) return 0;
  sort(cord.begin(), cord.end());
  vector<pair<int, int>> event;
  for (auto& it : segs) {
    int x = lower_bound(cord.begin(), cord.end(), it.first) - cord.begin() + 1;
    int y = lower_bound(cord.begin(), cord.end(), it.second) - cord.begin() + 1;
    event.emplace_back(x, -1);
    event.emplace_back(y, +x);
  }
  Fenwick f(cord.size() + 5);
  sort(event.begin(), event.end());
  long long ans = 0;
  int bal = 0;
  for (auto& it : event) {
    if (it.second == -1) {
      f.upd(it.first, +1);
      bal++;
    } else {
      f.upd(it.second, -1);
      bal--;
      ans += bal - f.get(it.second);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    if (x[i] != 0 || y[i] != 0) {
      ang[i] = atan2l(y[i], x[i]);
    }
  }
  long double le = 0;
  long double ri = 3e4;
  long long tot = (1LL * n * (n - 1)) / 2;
  for (int iter = 0; iter < 60; iter++) {
    long double mid = (le + ri) / 2;
    long long f = calc(mid);
    if (f > tot - k)
      le = mid;
    else
      ri = mid;
  }
  cout << fixed << setprecision(12) << (le + ri) / 2;
  return 0;
}
