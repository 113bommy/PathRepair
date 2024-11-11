#include <bits/stdc++.h>
using namespace std;
struct no {
  int x, y, r;
};
no A, B, b, a;
int dist(no u, no v) {
  return (u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y);
}
bool contido(no v, no u) {
  if (u.r < v.r) return 0;
  if ((sqrt(dist(v, u)) + (double)((v.r)) - 1e-7 < (double)(u.r))) return 1;
  return 0;
}
bool disjunto(no v, no u) {
  if (sqrt(dist(u, v)) > (double)(v.r + u.r) - 1e-7) return 1;
  return 0;
}
int main() {
  cin >> a.x >> a.y >> a.r >> A.r;
  A.x = a.x, A.y = a.y;
  cin >> b.x >> b.y >> b.r >> B.r;
  B.x = b.x, B.y = b.y;
  if (B.r < A.r) {
    swap(B, A);
    swap(a, b);
  }
  int ans;
  if (contido(A, B)) {
    if (contido(A, b))
      ans = 4;
    else if (contido(a, b) || contido(b, a))
      ans = 2;
    else if (disjunto(b, A))
      ans = 2;
    else
      ans = 1;
  } else if (disjunto(A, B)) {
    ans = 4;
  } else {
    if (contido(a, b) || contido(a, b))
      ans = 1;
    else {
      ans = 0;
      if (disjunto(a, B)) ans++;
      if (disjunto(b, A)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
