#include <bits/stdc++.h>
using namespace std;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};
const long long MOD = 1e9 + 7;
const long long INF = 1e9;
const double EPS = 1e-5;
int n, r;
vector<double> f, s, p;
vector<vector<int>> vis(55, vector<int>(6000));
int vf = 0;
vector<vector<double>> mem(55, vector<double>(6000));
double solve(int idx, int tmt, double mid) {
  if (tmt > r) return mid;
  if (idx == n) return 0;
  if (vis[idx][tmt] == vf) return mem[idx][tmt];
  double ret = 0;
  ret = (f[idx] + solve(idx + 1, tmt + f[idx], mid)) * p[idx];
  ret += (s[idx] + solve(idx + 1, tmt + s[idx], mid)) * (1.0 - p[idx]);
  ret = min(ret, mid);
  vis[idx][tmt] = vf;
  return mem[idx][tmt] = ret;
}
double bs() {
  double a = 0, b = INF, mid = (a + b) / 2.0;
  for (int i = 0; i < 500; i++) {
    vf++;
    if (solve(0, 0, mid) < mid)
      b = mid;
    else
      a = mid;
    mid = (a + b) / 2.0;
  }
  return mid;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> r;
  f.resize(n), s = p = f;
  for (int i = 0; i < n; i++) cin >> f[i] >> s[i] >> p[i], p[i] /= 100.0;
  cout << fixed << setprecision(10) << bs() << endl;
  cin.ignore(), cin.get();
}
