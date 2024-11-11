#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int N = (1 << 14);
const int OO = (long long)1 * 1e9;
const long long mod = 1e9 + 7;
int n, l, k, a[200];
double p[200];
bool vis[201][402][201];
double mem[201][402][201];
double go(int in, int s, int r) {
  if (in == n) {
    if (r > 0 || s < 0) return 0;
    return 1;
  }
  double &ret = mem[in][s + 200][r];
  if (vis[in][s + 200][r]) return ret;
  vis[in][s + 200][r] = 1;
  ret = (1 - p[in]) * go(in + 1, s, r);
  if (a[in] == -1)
    ret += p[in] * go(in + 1, s - 1, max(0, r - 1));
  else
    ret += p[in] * go(in + 1, min(s + a[in], 200), max(0, r - 1));
  return ret;
}
int main() {
  cin >> n >> l >> k;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] /= 100;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << fixed << setprecision(12) << go(0, k, l);
  return 0;
}
