#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
  point(int _x = 0, int _y = 0) {
    x = _x;
    y = _y;
  }
  bool operator==(point w) { return (x == w.x && y == w.y); }
};
bool is_between(point f, point t, point w) {
  return (f.x <= w.x && w.x <= t.x && f.y <= w.y && w.y <= t.y);
}
int n;
point V[5000];
vector<int> X, Y;
int fx1, tx1, fx2, tx2;
int fy1, ty1, fy2, ty2;
bool TRY_RECT(point f1, point t1, point f2, point t2) {
  for (int i = 0; i < n; ++i)
    if (!is_between(f1, t1, V[i]) && !is_between(f2, t2, V[i])) return false;
  return true;
}
vector<point> F1, T1, F2, T2;
bool TRY(int delta) {
  fx1 = X[0];
  tx1 = X[0] + delta;
  fx2 = X.back() - delta;
  tx2 = X.back();
  fy1 = Y[0];
  ty1 = Y[0] + delta;
  fy2 = Y.back() - delta;
  ty2 = Y.back();
  F1.clear();
  T1.clear();
  F2.clear();
  T2.clear();
  if (TRY_RECT(point(fx1, fy1), point(tx1, ty1), point(fx2, fy2),
               point(tx2, ty2))) {
    F1.push_back(point(fx1, fy1));
    T1.push_back(point(tx1, ty1));
    F2.push_back(point(fx2, fy2));
    T2.push_back(point(tx2, ty2));
  }
  if (TRY_RECT(point(fx1, fy2), point(tx1, ty2), point(fx2, fy1),
               point(tx2, ty1))) {
    F1.push_back(point(fx1, fy2));
    T1.push_back(point(tx1, ty2));
    F2.push_back(point(fx2, fy1));
    T2.push_back(point(tx2, ty1));
  }
  return (!F1.empty());
}
const long long mod = 1000000007;
char C[5000][4];
void color(point f, point t, int w) {
  for (int i = 0; i < n; ++i)
    if (is_between(f, t, V[i])) C[i][w] = 1;
}
long long calc(int delta) {
  int i, j, k, l;
  TRY(delta);
  point f1(fx1, fy1), t1(tx1, ty1), f2(fx2, fy2), t2(tx2, ty2);
  long long br = 2;
  for (i = 0; i < n; ++i)
    if (is_between(f1, t1, V[i]) && is_between(f2, t2, V[i]))
      br = (br * 2) % mod;
  if (F1.size() > 0) {
    color(F1[0], T1[0], 0);
    color(F1[1], T1[1], 1);
    bool OK = false;
    for (i = 0; i < n; ++i)
      if (C[i][0] ^ C[i][1]) {
        OK = true;
        break;
      }
    if (!OK) F1.pop_back();
  }
  return (br * F1.size()) % mod;
}
int main() {
  int i, j, x, y;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d%d", &V[i].x, &V[i].y);
  for (i = 0; i < n; ++i) {
    V[i] = point(V[i].x + V[i].y, V[i].x - V[i].y);
    X.push_back(V[i].x);
    Y.push_back(V[i].y);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  int LE = 0, RE = 40010, M;
  while (1) {
    if (RE - LE < 2) {
      if (TRY(LE))
        M = LE;
      else
        M = RE;
      break;
    }
    M = (LE + RE) / 2;
    if (TRY(M))
      RE = M;
    else
      LE = M;
  }
  cout << M << '\n' << calc(M) << '\n';
  return 0;
}
