#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-10;
const int MODULO = 1000000007;
typedef struct {
  int i, m, v;
} P;
vector<P> mv;
bool mLt(const P& x, const P& y) {
  return (x.m != y.m) ? less<int>()(x.m, y.m) : less<int>()(x.v, y.v);
}
int n, k, h;
bool C(double t) {
  int i = 1;
  for (__typeof__((mv).begin()) it = (mv).begin(); it != (mv).end(); ++it) {
    if ((double)i * h <= (*it).v * t) i++;
    if (i > k) break;
  }
  return i > k;
}
int main() {
  cin >> n >> k >> h;
  mv.resize(n);
  for (int i = 0; i < n; i++) mv[i].i = i + 1;
  for (int i = 0; i < n; i++) cin >> mv[i].m;
  for (int i = 0; i < n; i++) cin >> mv[i].v;
  sort(mv.begin(), mv.end(), mLt);
  double l = 0, r = 1e10;
  double t;
  for (int i = 0; i < 100; i++) {
    t = (l + r) / 2;
    if (C(t))
      r = t;
    else
      l = t;
  }
  int cnt = 1;
  for (__typeof__((mv).begin()) it = (mv).begin(); it != (mv).end(); ++it) {
    if ((double)cnt * h <= (*it).v * t + EPS) {
      printf("%d ", (*it).i);
      cnt++;
    }
    if (cnt > k) break;
  }
  puts("\n");
  return 0;
}
