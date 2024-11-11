#include <bits/stdc++.h>
void Get(int &T) {
  char C;
  bool F = 0;
  for (; C = getchar(), C < '0' || C > '9';)
    if (C == '-') F = 1;
  for (T = C - '0'; C = getchar(), C >= '0' && C <= '9'; T = T * 10 + C - '0')
    ;
  F && (T = -T);
}
double t1, t2;
double T1, T2;
struct Point {
  double X, Y;
} O, A, B;
double Dist2(Point A, Point B) {
  double DX = A.X - B.X;
  double DY = A.Y - B.Y;
  return DX * DX + DY * DY;
}
double Dist(Point A, Point B) { return sqrt(Dist2(A, B)); }
void Fix(double &X) {
  if (X < -1) X = -1;
  if (X > 1) X = 1;
}
void Init() {
  scanf("%lf%lf", &t1, &t2);
  scanf("%lf%lf", &O.X, &O.Y);
  scanf("%lf%lf", &B.X, &B.Y);
  scanf("%lf%lf", &A.X, &A.Y);
}
double Min(double X, double Y) { return X < Y ? X : Y; }
void Cross(Point A, double RA, Point B, double RB, double &L, double &R) {
  if (RA + RB + (1e-10) < Dist(A, B)) {
    L = 1;
    R = 0;
    return;
  }
  if (RA < RB) {
    std::swap(A, B);
    std::swap(RA, RB);
  }
  if (Dist(A, B) + (1e-10) < RA - RB) {
    if (L < B.X - RB) L = B.X - RB;
    if (R > B.X + RB) R = B.X + RB;
    return;
  }
  double Theta = atan2(B.Y - A.Y, B.X - A.X);
  double Alpha = (RA * RA + Dist2(A, B) - RB * RB) / (2 * RA * Dist(A, B));
  Fix(Alpha);
  Alpha = acos(Alpha);
  double LAlpha = Theta - Alpha;
  double RAlpha = Theta + Alpha;
  double X1 = A.X + RA * cos(LAlpha);
  double X2 = A.X + RA * cos(RAlpha);
  if (X1 > X2) std::swap(X1, X2);
  if (Dist((Point){B.X - RB, B.Y}, A) < RA + (1e-10) && X1 > B.X - RB)
    X1 = B.X - RB;
  if (Dist((Point){B.X + RB, B.Y}, A) < RA + (1e-10) && X2 < B.X + RB)
    X2 = B.X + RB;
  if (Dist((Point){A.X - RA, A.Y}, B) < RB + (1e-10) && X1 > A.X - RA)
    X1 = A.X - RA;
  if (Dist((Point){A.X + RA, A.Y}, B) < RB + (1e-10) && X2 < A.X + RA)
    X2 = A.X + RA;
  if (L < X1) L = X1;
  if (R > X2) R = X2;
}
bool Check(double X) {
  double L = -1e60;
  double R = 1e60;
  double R1 = X;
  double R2 = T1 - Dist(A, B) - X;
  double R3 = T2 - X;
  Cross(O, R1, A, R2, L, R);
  Cross(O, R1, B, R3, L, R);
  Cross(A, R2, B, R3, L, R);
  return L < R + (1e-10);
}
double BinSrh(double L, double R) {
  double Mid;
  for (;;) {
    if (R - L <= 1e-11) return (L + R) * 0.5;
    Mid = L + R;
    Mid *= 0.5;
    if (Check(Mid))
      L = Mid;
    else
      R = Mid;
  }
}
double Ans;
void Work() {
  A.X -= O.X;
  A.Y -= O.Y;
  B.X -= O.X;
  B.Y -= O.Y;
  O.X = O.Y = 0;
  T1 = t1 + Dist(O, A) + Dist(A, B);
  T2 = t2 + Dist(O, B);
  if (T2 >= Dist(O, A) + Dist(A, B)) {
    Ans = Min(T1, T2);
  } else {
    Ans = BinSrh(0, Min(T1, T2));
  }
}
void Output() { printf("%.9lf\n", Ans); }
int main() {
  Init();
  Work();
  Output();
  return 0;
}
