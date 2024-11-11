#include <bits/stdc++.h>
using namespace std;
const int N = 610;
int n;
struct Node {
  double x, y;
  Node operator+(Node A) { return (Node){x + A.x, y + A.y}; }
  Node operator-(Node A) { return (Node){x - A.x, y - A.y}; }
  Node operator^(double t) { return (Node){t * x, t * y}; }
  double operator*(Node A) { return x * A.y - y * A.x; }
  double dis() { return sqrt(x * x + y * y); }
} P[N], E[N], Mv[N], o1, o2, O[N][N], A[N], C[N];
int yes[N][N], tt, c;
int nxt(int r) { return r > n ? r - n : r; }
Node Getcrs(Node a1, Node a2, Node b1, Node b2) {
  Node a = a2 - a1, b = b2 - b1, c = b1 - a1;
  double t = (b * c) / (b * a);
  return a1 + (a ^ t);
}
void Cut(Node a, Node b) {
  A[tt + 1] = A[1];
  c = 0;
  for (int i = 1; i <= tt; i++) {
    double v1 = (A[i] - a) * (A[i] - b);
    double v2 = (A[i + 1] - a) * (A[i + 1] - b);
    if (v1 >= 0) C[++c] = A[i];
    if (v1 * v2 < 0) C[++c] = Getcrs(A[i], A[i + 1], a, b);
  }
  tt = c;
  for (int i = 1; i <= tt; i++) A[i] = C[i];
}
int Check(double r) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) yes[i][j] = 0;
  for (int L = 1; L <= n; L++) {
    tt = n, c = 0;
    for (int i = 1; i <= n; i++) A[i] = P[i];
    for (int R = L; R <= L + n && tt; R++) {
      Cut(P[R + 1] + (Mv[R] ^ r), P[R] + (Mv[R] ^ r));
      if (tt) yes[L][nxt(R)] = 1, O[L][nxt(R)] = A[1];
    }
  }
  for (int L = 1; L <= n; L++)
    for (int R = L; R <= L + n; R++)
      if (yes[L][nxt(R)] && yes[nxt(R + 1)][nxt(L + n - 1)])
        return o1 = O[L][nxt(R)], o2 = O[nxt(R + 1)][nxt(L + n - 1)], 1;
  return 0;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lf%lf", &P[i].x, &P[i].y);
  for (int i = 1; i <= n * 2; i++) P[i + n] = P[i];
  for (int i = 1; i <= n * 3; i++) {
    E[i] = P[i + 1] - P[i];
    Mv[i] = (Node){-E[i].y, E[i].x};
    Mv[i] = Mv[i] ^ (1.0 / Mv[i].dis());
  }
  double l = 0, r = 1e7, ans;
  while (fabs(r - l) > 1e-6) {
    double mid = (l + r) / 2;
    if (Check(mid))
      r = mid, ans = mid;
    else
      l = mid;
  }
  printf("%.10f\n%.10f %.10f\n%.10f %.10f\n", ans, o1.x, o1.y, o2.x, o2.y);
}
