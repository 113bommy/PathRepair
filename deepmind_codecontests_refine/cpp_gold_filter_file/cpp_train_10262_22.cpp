#include <bits/stdc++.h>
using namespace std;
int IN() {
  int x = 0, f = 0, ch;
  for (; (ch = getchar()) < '0' || ch > '9';) f = (ch == '-');
  for (; ch >= '0' && ch <= '9'; (ch = getchar())) x = x * 10 + ch - '0';
  return f ? -x : x;
}
const double Pi = acos(-1), eps = 1e-11;
int N, M, T, C, ID[2005];
struct Nod {
  double x, y;
} A[2005], B[2005];
struct Opt {
  double x;
  int k, t;
} Q[2005 << 3];
bool Equ(double a, double b) { return abs(a - b) < eps; }
double Dis(const Nod& a, const Nod& b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Upd(double l, double r, int k) {
  if (r - l < 0) return;
  for (; l < 0; l += 2 * Pi)
    ;
  for (; l > 2 * Pi; l -= 2 * Pi)
    ;
  for (; r < 0; r += 2 * Pi)
    ;
  for (; r > 2 * Pi; r -= 2 * Pi)
    ;
  if (l < r)
    Q[++T] = (Opt){l, k, 1}, Q[++T] = (Opt){r, k, -1};
  else
    Q[++T] = (Opt){0, k, 1}, Q[++T] = (Opt){r, k, -1}, Q[++T] = (Opt){l, k, 1},
    Q[++T] = (Opt){2 * Pi, k, -1};
}
bool Cmp(const Opt& a, const Opt& b) { return a.x < b.x; }
bool RightRed(int d, double r) {
  T = 0;
  Upd(0, 2 * Pi, 1);
  for (int i = 1, lim = M; i <= lim; i++) {
    double a = Dis(A[d], B[i]);
    if (r + r <= a) continue;
    double o = atan2(B[i].y - A[d].y, B[i].x - A[d].x), t = acos(a / r / 2);
    Upd(o - t, o + t, 0);
  }
  sort(Q + 1, Q + T + 1, Cmp);
  int s1 = 0, s2 = 0;
  for (int i = 1, j; i <= T; i = j) {
    for (j = i; j <= T && Equ(Q[i].x, Q[j].x); j++)
      if (Q[j].k == 1)
        s1 += Q[j].t;
      else
        s2 += Q[j].t;
    if (s1 && !s2) return 1;
  }
  return 0;
}
bool RightBlue(int d, double r) {
  T = 0;
  for (int i = 1, lim = M; i <= lim; i++)
    if (i != d) {
      double a = Dis(B[d], B[i]);
      if (r + r <= a) continue;
      double o = atan2(B[i].y - B[d].y, B[i].x - B[d].x), t = acos(a / r / 2);
      Upd(o - t, o + t, 0);
    }
  for (int i = 1, lim = N; i <= lim; i++) {
    double a = Dis(B[d], A[i]);
    if (r + r <= a) continue;
    double o = atan2(A[i].y - B[d].y, A[i].x - B[d].x), t = acos(a / r / 2);
    Upd(o - t, o + t, 1);
  }
  sort(Q + 1, Q + T + 1, Cmp);
  int s1 = 0, s2 = 0;
  for (int i = 1, j; i <= T; i = j) {
    for (j = i; j <= T && Equ(Q[i].x, Q[j].x); j++)
      if (Q[j].k == 1)
        s1 += Q[j].t;
      else
        s2 += Q[j].t;
    if (s1 && !s2) return 1;
  }
  return 0;
}
bool check(double r) {
  for (int i = 1, lim = N; i <= lim; i++)
    if (RightRed(i, r)) return 1;
  for (int i = 1, lim = M; i <= lim; i++)
    if (RightBlue(i, r)) return 1;
  return 0;
}
int main(int argc, char* argv[]) {
  N = IN();
  M = IN();
  for (int i = 1, lim = N; i <= lim; i++) A[i] = (Nod){1. * IN(), 1. * IN()};
  for (int i = 1, lim = M; i <= lim; i++) B[i] = (Nod){1. * IN(), 1. * IN()};
  if (check(1e10)) return puts("-1"), 0;
  for (int i = 1, lim = N; i <= lim; i++) ID[++C] = i;
  for (int i = 1, lim = M; i <= lim; i++) ID[++C] = N + i;
  random_shuffle(ID + 1, ID + N + 1);
  random_shuffle(ID + N + 1, ID + C + 1);
  double Ans = 0;
  for (int k = 1, lim = C; k <= lim; k++) {
    if (ID[k] <= N) {
      int i = ID[k];
      if (RightRed(i, Ans)) {
        double l = Ans, r = 1e10;
        for (; l + (1e-6) < r;) {
          double Mid = (l + r) * .5;
          if (RightRed(i, Mid))
            l = Mid;
          else
            r = Mid;
        }
        Ans = l;
      }
    } else {
      int i = ID[k] - N;
      if (RightBlue(i, Ans)) {
        double l = Ans, r = 1e10;
        for (; l + (1e-6) < r;) {
          double Mid = (l + r) * .5;
          if (RightBlue(i, Mid))
            l = Mid;
          else
            r = Mid;
        }
        Ans = l;
      }
    }
  }
  printf("%.12lf\n", Ans);
  return 0;
}
