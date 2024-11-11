#include <bits/stdc++.h>
using namespace std;
struct pnt {
  long long x, y;
  pnt(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}
};
long long dist2(const pnt& A) { return A.x * A.x + A.y * A.y; }
long long scalar(const pnt& A, const pnt& B) { return A.x * B.x + A.y * B.y; }
long long cross(const pnt& A, const pnt& B) { return A.x * B.y - A.y * B.x; }
bool operator==(const pnt& A, const pnt& B) { return A.x == B.x && A.y == B.y; }
bool operator!=(const pnt& A, const pnt& B) { return !(A == B); }
pnt operator-(const pnt& A, const pnt& B) { return pnt(A.x - B.x, A.y - B.y); }
long long lcm(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
bool in_line(const pnt& A, const pnt& B, const pnt& C) {
  pnt CB = C - B, AB = A - B;
  long long scal = scalar(CB, AB);
  if (scal >= 0) return false;
  long long a = dist2(AB), b = dist2(CB);
  long long c = abs(scal);
  long long lcm_l = lcm(a, c);
  long long lcm_r = lcm(c, b);
  long long num_l = a / lcm_l;
  long long denum_l = c / lcm_l;
  long long num_r = c / lcm_r;
  long long denum_r = b / lcm_r;
  return num_l == num_r && denum_l == denum_r;
}
struct seg {
  pnt A, B;
};
const long long MAGIC_RATIO = 4LL;
const long long MAGIC_SQ = MAGIC_RATIO * MAGIC_RATIO;
bool ok_ratio(long long one, long long two) {
  if (one >= two) swap(one, two);
  if (one == 0) return two == 0;
  return one >= (two + MAGIC_SQ - 1) / MAGIC_SQ;
}
bool ok_ratio(const pnt& A, const pnt& B, const pnt& C) {
  long long one = dist2(B - A);
  long long two = dist2(C - B);
  return ok_ratio(one, two);
}
bool solve(seg first, seg second, seg third) {
  if (first.A != second.A) swap(second.A, second.B);
  if (first.A != second.A) swap(first.A, first.B);
  if (first.A != second.A) swap(second.A, second.B);
  if (first.A != second.A) return false;
  if (!in_line(first.A, third.A, first.B)) swap(third.A, third.B);
  if (!in_line(first.A, third.A, first.B)) return false;
  if (!in_line(second.A, third.B, second.B)) return false;
  if (!ok_ratio(first.A, third.A, first.B)) return false;
  if (!ok_ratio(second.A, third.B, second.B)) return false;
  pnt v1 = first.B - first.A;
  pnt v2 = second.B - second.A;
  if (scalar(v1, v2) < 0) return false;
  if (cross(v1, v2) == 0) return false;
  return true;
}
int main() {
  int n;
  cin >> n;
  seg A[3];
  for (int tt = 0; tt < n; tt++) {
    for (int i = 0; i < 3; i++)
      cin >> A[i].A.x >> A[i].A.y >> A[i].B.x >> A[i].B.y;
    bool result = false;
    if (solve(A[0], A[1], A[2])) result = true;
    if (solve(A[1], A[2], A[0])) result = true;
    if (solve(A[2], A[0], A[1])) result = true;
    if (result)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
