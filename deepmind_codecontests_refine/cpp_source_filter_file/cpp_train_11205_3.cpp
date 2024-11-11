#include <bits/stdc++.h>
const double Exp = 1e-8;
using namespace std;
struct point {
  double x, y;
};
point A, B, C;
double L1, L2;
double a, b, c;
double sim_ans;
double dis(point &A, point &B) {
  return sqrt(((A.x - B.x) * (A.x - B.x)) + ((A.y - B.y) * (A.y - B.y)));
}
double muilt(point &P, point &A, point &B) {
  return (A.x - P.x) * (B.y - P.y) - (A.y - P.y) * (B.x - P.x);
}
double dot(point &P, point &A, point &B) {
  return (A.x - P.x) * (B.x - P.x) + (A.y - P.y) * (B.y - P.y);
}
bool cross(point &A, point &B, point &C, point &D, point &F) {
  if (muilt(A, B, C) * muilt(A, B, D) > 0 ||
      muilt(C, D, A) * muilt(C, D, B) > 0)
    return false;
  double kA = fabs(muilt(A, C, D)), kB = fabs(muilt(B, C, D)),
         k = kA / (kA + kB);
  F.x = A.x + (B.x - A.x) * k;
  F.y = A.y + (B.y - A.y) * k;
  return true;
}
void special_doit() {
  if (dot(C, A, B) <= 0)
    cout << sim_ans << endl;
  else {
    if (dot(A, B, C) <= 0) {
      if (L2 >= 2 * dis(A, C))
        cout << sim_ans << endl;
      else {
        if (L1 >= 2 * dis(A, B))
          cout << dis(A, B) + L2 << endl;
        else
          cout << L2 / 2 << endl;
      }
    } else {
      if (L2 >= 2 * dis(B, C))
        cout << sim_ans << endl;
      else
        cout << dis(A, B) + L2 / 2 << endl;
    }
  }
}
point update(point P, double r) {
  if (dis(P, A) < Exp) return P;
  double k = r / dis(P, A);
  P.x = A.x + (P.x - A.x) * k;
  P.y = A.y + (P.y - A.y) * k;
  return P;
}
bool solve(double r) {
  double max1 = b + L1 - r;
  double max2 = c + L2 - r;
  point s = update(B, r), t = update(C, r);
  while (dis(s, t) > Exp) {
    point mid;
    mid.x = (s.x + t.x) / 2;
    mid.y = (s.y + t.y) / 2;
    mid = update(mid, r);
    double LB, LC;
    point foc;
    if (cross(A, mid, B, C, foc))
      LB = dis(foc, B), LC = dis(foc, C);
    else
      LB = dis(mid, B), LC = dis(mid, C);
    if (LC < max1 + Exp) {
      if (LB < max2 + Exp)
        return true;
      else
        t = mid;
    } else {
      if (LB < max2 + Exp)
        s = mid;
      else
        return false;
    }
  }
  return true;
}
void doit() {
  cout.precision(10);
  cin >> L1 >> L2 >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;
  a = dis(B, C);
  b = dis(A, C);
  c = dis(A, B);
  sim_ans = min(L1 + dis(A, C) + dis(B, C), L2 + dis(A, B));
  if (muilt(A, B, C) == 0) {
    special_doit();
    return;
  }
  if (L2 > dis(A, C) + dis(C, B) - dis(A, B) - Exp ||
      L1 > dis(B, C) * 2 - Exp) {
    cout << sim_ans << endl;
    return;
  }
  double s = 0, t = min(b + L1, c + L2);
  while (t - s > Exp) {
    double mid = (s + t) / 2;
    if (solve(mid))
      s = mid;
    else
      t = mid;
  }
  cout << s << endl;
}
int main() {
  doit();
  return 0;
}
