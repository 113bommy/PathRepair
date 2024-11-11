#include <bits/stdc++.h>
using namespace std;
struct vect3d {
  long double x, y, z;
  vect3d() {}
  vect3d(long double a, long double b, long double c) { x = a, y = b, z = c; }
  void read() { cin >> x >> y >> z; }
  long double len() { return sqrt(x * x + y * y + z * z); }
  void print() {
    cout.precision(6);
    cout << fixed << x << " " << y << " " << z << endl;
  }
};
vect3d operator-(vect3d a, vect3d b) {
  return vect3d(a.x - b.x, a.y - b.y, a.z - b.z);
}
vect3d operator+(vect3d a, vect3d b) {
  return vect3d(a.x + b.x, a.y + b.y, a.z + b.z);
}
bool operator==(vect3d a, vect3d b) {
  return (a.x == b.x && a.y == b.y && a.z == b.z);
}
vect3d operator*(vect3d v, long double sc) {
  return vect3d(v.x * sc, v.y * sc, v.z * sc);
}
const int N = int(1e4 + 5);
const double eps = 1e-9;
vect3d p[N];
int main() {
  int n;
  scanf("%d", &n);
  n++;
  for (int i = 0; i < n; i++) {
    p[i].read();
  }
  int vp, vs;
  cin >> vp >> vs;
  vect3d start;
  start.read();
  if (start == p[0]) {
    cout << "YES\n0\n";
    start.print();
    return 0;
  }
  long double total = 0;
  int reach = -1;
  for (int i = 1; i < n; i++) {
    total += (p[i] - p[i - 1]).len() / vs;
    cerr << total * vp << " " << (p[i] - start).len() << endl;
    if (total + eps > (p[i] - start).len() / vp) {
      total -= (p[i] - p[i - 1]).len() / vs;
      reach = i;
      break;
    }
  }
  if (reach == -1) {
    puts("NO");
    return 0;
  }
  vect3d dir = p[reach] - p[reach - 1];
  long double l = 0, r = 1;
  for (int i = 0; i < 1000; i++) {
    long double mid = (l + r) / 2;
    vect3d pos = p[reach - 1] + (dir * mid);
    if (total + (dir.len() * mid) / vs + eps > (pos - start).len() / vp)
      r = mid;
    else
      l = mid;
  }
  puts("YES");
  vect3d pos = p[reach - 1] + (dir * r);
  cout.precision(6);
  cout << fixed << (pos - start).len() / vp << endl;
  pos.print();
  return 0;
}
