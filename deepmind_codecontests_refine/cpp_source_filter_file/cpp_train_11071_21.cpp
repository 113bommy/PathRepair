#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
};
point a, b;
double d(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int ok1(int ra, int rb) {
  double t = d(a, b);
  int t1 = ra - rb;
  if (t1 < 0) return 0;
  if (t - t1 < 1E-6)
    return 1;
  else
    return 0;
}
int ok2(int ra, int rb) {
  double t = d(a, b);
  int t1 = ra - rb;
  if (t1 < 0) t1 = -t1;
  if (t >= ra + rb - 1E-6)
    return 1;
  else
    return 0;
}
int main() {
  int ra, rb, Ra, Rb, ans = 0;
  cin >> a.x >> a.y >> ra >> Ra;
  cin >> b.x >> b.y >> rb >> Rb;
  if (ok1(ra, Rb) || ok1(rb, Ra) || ok2(Ra, Rb))
    ans = 4;
  else {
    int t = d(a, b);
    if (t >= ra + Rb || t <= rb - ra) ans++;
    if (t >= rb + Ra || t <= ra - rb) ans++;
    if (ok1(Ra, Rb) || ok1(Rb, Ra)) ans++;
  }
  cout << ans << endl;
  return 0;
}
