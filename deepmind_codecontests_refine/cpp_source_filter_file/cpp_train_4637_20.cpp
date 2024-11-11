#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
void __never(int a) { printf("\nOPS %d", a); }
struct T {
  double x, y, z;
};
double dist2(T A, T B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) +
         (A.z - B.z) * (A.z - B.z);
}
int n;
T p[10100];
double v_p, v_s;
T start;
void sol() {
  double tme = 0.;
  for (int a = (1); a <= (n); a++) {
    tme += sqrt(dist2(p[a], p[a + 1])) / v_s;
    double t2 = sqrt(dist2(p[a + 1], start)) / v_p;
    if (tme > t2 - 0.000000001) {
      double mi = 0., ma = 1.;
      while (1) {
        if (abs(mi - ma) < 0.000000001) {
          double sr = 0.5 * (mi + ma);
          T C;
          C.x = p[a + 1].x + (p[a].x - p[a + 1].x) * sr;
          C.y = p[a + 1].y + (p[a].y - p[a + 1].y) * sr;
          C.z = p[a + 1].z + (p[a].z - p[a + 1].z) * sr;
          double tt1 = tme - sqrt(dist2(p[a + 1], C)) / v_s;
          double tt2 = sqrt(dist2(C, start)) / v_p;
          printf("YES\n");
          printf("%.10lf\n", tt1);
          printf("%.10lf %.10lf %.10lf\n", C.x, C.y, C.z);
          return;
        }
        double sr = 0.5 * (mi + ma);
        T C;
        C.x = p[a + 1].x + (p[a].x - p[a + 1].x) * sr;
        C.y = p[a + 1].y + (p[a].y - p[a + 1].y) * sr;
        C.z = p[a + 1].z + (p[a].z - p[a + 1].z) * sr;
        double tt1 = tme - sqrt(dist2(p[a + 1], C)) / v_s;
        double tt2 = sqrt(dist2(C, start)) / v_p;
        if (tt1 > tt2)
          mi = sr;
        else
          ma = sr;
      }
      return;
    }
  }
  printf("NO\n");
}
int main() {
  cin >> n;
  for (int a = (1); a <= (n + 1); a++) cin >> p[a].x >> p[a].y >> p[a].z;
  cin >> v_p >> v_s;
  cin >> start.x >> start.y >> start.z;
  sol();
  return 0;
}
