#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 28;
const double INF = 1e12, EPS = 1e-9;
double a[200000], p[100000];
void run() {
  int n, l, v1, v2;
  cin >> n >> l >> v1 >> v2;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  for (int i = 0; i < n; i++) a[i + n] = a[i] + 2 * l;
  double d = v2 * 1.0 * l / (v1 + v2);
  map<double, int> ps;
  for (int i = 0; i < n; i++) ps[a[i]]--;
  for (int i = 0; i < 2 * n; i++)
    if (0 <= a[i] - d && a[i] - d < 2 * l) ps[a[i] - d]++;
  if (!ps.count(0)) ps[0] = 0;
  if (!ps.count(2 * l)) ps[2 * l] = 0;
  int cnt = lower_bound(a, a + 2 * n, d) - a;
  for (__typeof((ps).begin()) i = (ps).begin(); i != (ps).end(); i++) {
    cnt += i->second;
    map<double, int>::iterator it = i;
    it++;
    if (it == ps.end()) break;
    p[cnt] += (it->first - i->first) / (2 * l);
  }
  for (int i = 0; i < n + 1; i++) printf("%.20f\n", p[i]);
}
int main() { run(); }
