#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const double eps = 1e-5;
const double pi = acos(-1);
int x[N], y[N], n;
double get(int a, int b) {
  double aa = x[a] - x[b];
  double bb = y[a] - y[b];
  return atan2(bb, aa);
}
long long C(long long t) { return t * (t - 1) / 2LL; }
long long calc(int q) {
  vector<double> a;
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    if (i == q) continue;
    a.push_back(get(i, q));
    a.push_back(get(i, q) + pi * 2);
  }
  sort(a.begin(), a.end());
  int r = 0;
  for (int l = 0; l < n - 1; l++) {
    while (a[l] + pi - a[r] > eps) r++;
    long long now1 = ((r - 1) - l + 1) - 1;
    long long now2 = (n - 1) - (now1 + 1);
    ret += C(now1) * C(now2);
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += calc(i);
  cout << ans / 2 << endl;
}
