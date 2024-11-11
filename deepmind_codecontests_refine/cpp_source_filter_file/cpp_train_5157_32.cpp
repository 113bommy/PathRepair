#include <bits/stdc++.h>
using namespace std;
struct pnt {
  int x, y;
  pnt(){};
  pnt(int x, int y) : x(x), y(y){};
};
struct vect {
  int x, y;
  vect(){};
  vect(int x, int y) : x(x), y(y){};
  vect(pnt a, pnt b) : x(b.x - a.x), y(b.y - a.y){};
};
bool left(vect a, vect b) { return (a.x * b.y - a.y * b.x) > 0; }
int main() {
  int n;
  scanf("%d", &n);
  vector<pnt> ps(n + 1);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ps[i] = pnt(x, y);
  }
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    cnt += left(vect(ps[i], ps[i + 1]), vect(ps[i + 1], ps[i + 2]));
  }
  printf("%d", cnt);
  return 0;
}
