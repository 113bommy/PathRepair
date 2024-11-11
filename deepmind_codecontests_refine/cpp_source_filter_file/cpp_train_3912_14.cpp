#include <bits/stdc++.h>
using namespace std;
struct card {
  char c;
  int r, b;
};
const double eps = 1e-6;
int n;
vector<card> p;
long long sim() {
  long long res = 0, A = 0, B = 0, rcnt = 0, bcnt = 0;
  for (int i = 0; i < n; i++) {
    long long rcost = max(p[i].r - A, 0LL);
    long long bcost = max(p[i].b - B, 0LL);
    long long collect = max(0LL, max(rcost - rcnt, bcost - bcnt));
    rcnt = rcnt + collect - rcost;
    bcnt = bcnt + collect - bcost;
    res = res + collect + 1;
    if (p[i].c == 'R')
      A++;
    else
      B++;
  }
  return res;
}
int main() {
  srand(69);
  cin >> n;
  p.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].c >> p[i].r >> p[i].b;
  }
  if (n == 1) {
    cout << max(p[0].r, p[0].b) + 1 << endl;
    return 0;
  }
  long long cur = 1e9;
  long long ans = cur;
  random_shuffle(p.begin(), p.end());
  double t0 = 1e9;
  for (double temp = t0; temp > eps; temp *= 0.999) {
    int r = rand() % n;
    int q = rand() % (n - 1);
    if (q >= r) q++;
    swap(p[r], p[q]);
    long long val = sim();
    ans = min(ans, val);
    if (cur > val) {
      cur = val;
    } else {
      double t = exp((cur - val) / temp);
      long long x = 1 + rand();
      long long y = 1 + rand();
      x %= y;
      if (x / (double)y <= t) {
        cur = val;
      } else {
        swap(p[r], p[q]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
