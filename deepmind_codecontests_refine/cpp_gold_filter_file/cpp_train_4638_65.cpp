#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const int MAXN = 10010;
const long double EPS = 1e-9;
long double p[MAXN][3];
long double ph[3];
long double v, vh;
int n;
long double dis(long double* a, long double* b) {
  return sqrt((long double)(a[0] - b[0]) * (a[0] - b[0]) +
              (a[1] - b[1]) * (a[1] - b[1]) + (a[2] - b[2]) * (a[2] - b[2]));
}
long double dot(long double* a, long double* b) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}
long double length(long double* a) { return sqrt(dot(a, a)); }
void binary_search(long double* le, long double* ri, long double t) {
  cout << "YES\n";
  long double mid[3], dis1[3], dis2[3], t_snitch, t_harry;
  long double le_const[3] = {le[0], le[1], le[2]};
  do {
    for (int i = 0; i < 3; i++) {
      mid[i] = (le[i] + ri[i]) / 2;
      dis1[i] = mid[i] - le_const[i];
      dis2[i] = mid[i] - ph[i];
    }
    t_snitch = length(dis1) / v + t;
    t_harry = length(dis2) / vh;
    if (t_snitch < t_harry) {
      for (int i = 0; i < 3; i++) le[i] = mid[i];
    } else {
      for (int i = 0; i < 3; i++) ri[i] = mid[i];
    }
  } while (dis(ri, le) > EPS);
  cout << setprecision(10) << fixed;
  cout << t_harry << "\n" << le[0] << " " << le[1] << " " << le[2] << "\n";
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i <= n; i++) cin >> p[i][0] >> p[i][1] >> p[i][2];
  cin >> vh >> v >> ph[0] >> ph[1] >> ph[2];
  if (ph[0] == p[0][0] && ph[1] == p[0][1] && ph[2] == p[0][2]) {
    cout << "YES\n0.0000000\n" << ph[0] << " " << ph[1] << " " << ph[2] << endl;
    return 0;
  }
  long double t = 0;
  for (int i = 0; i < n; i++) {
    long double t_nxt = t + dis(p[i], p[i + 1]) / v;
    if (t_nxt >= (dis(p[i + 1], ph) / vh)) {
      binary_search(p[i], p[i + 1], t);
      return 0;
    }
    t = t_nxt;
  }
  cout << "NO\n";
  return 0;
}
