#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long mypow(long long x, int st) {
  long long ans = {1};
  while (st) {
    if (st & 1) ans = (ans * x) % mod;
    x = (x * x) % mod;
    st /= 2;
  }
  return ans % mod;
}
struct track {
  double l, p;
  track() {}
  track(double l, double p) : l(l), p(p) {}
  double abc() { return (l * p / (1 - p)); }
};
bool cmp(track a, track b) { return a.abc() > b.abc(); }
int main() {
  int n;
  cin >> n;
  vector<track> v(n);
  for (int i = 0; i < n; i++) {
    double l, p;
    scanf("%f %f", &l, &p);
    p /= 100.0;
    v[i] = track(l, p);
  }
  sort(v.begin(), v.end(), cmp);
  double ans = 0.0;
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    ans = ans + v[i].l + (1 - v[i].p) * sum;
    sum += v[i].l * v[i].p;
  }
  printf("%.9f", ans);
}
