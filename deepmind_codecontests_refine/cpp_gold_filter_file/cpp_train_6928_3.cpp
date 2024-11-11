#include <bits/stdc++.h>
struct Point {
  long long X, Y;
  inline Point() {}
  inline Point(const long long &A, const long long &B) { X = A, Y = B; }
} A, B, C;
int top, Q, tempX, tempY, opt;
inline long long operator*(const Point &A, const Point &B) {
  return A.X * B.Y - A.Y * B.X;
}
inline Point operator-(const Point &A, const Point &B) {
  return Point(A.X - B.X, A.Y - B.Y);
}
inline bool uhull(const Point &A) { return A.Y > 0 || (A.Y == 0 && A.X > 0); }
struct cmp {
  inline bool operator()(const Point &A, const Point &B) {
    return (uhull(A) ^ uhull(B)) ? uhull(A) : A * B > 0;
  }
};
std::multiset<Point, cmp> Hull;
inline std::multiset<Point, cmp>::iterator Pre(
    std::multiset<Point, cmp>::iterator now) {
  return now == Hull.begin() ? --Hull.end() : --now;
}
inline std::multiset<Point, cmp>::iterator Nxt(
    std::multiset<Point, cmp>::iterator now) {
  return now == --Hull.end() ? Hull.begin() : ++now;
}
void insert(const Point &A) {
  std::multiset<Point, cmp>::iterator pos = Hull.insert(A);
  if ((*Nxt(pos) - *Pre(pos)) * (A - *Pre(pos)) > 0) {
    Hull.erase(pos);
  } else {
    while ((*Pre(pos) - A) * (*Pre(Pre(pos)) - A) > 0) Hull.erase(Pre(pos));
    while ((*Nxt(pos) - A) * (*Nxt(Nxt(pos)) - A) < 0) Hull.erase(Nxt(pos));
  }
}
bool check(const Point &A) {
  std::multiset<Point, cmp>::iterator pos = Hull.insert(A);
  bool chk = false;
  if ((*Nxt(pos) - *Pre(pos)) * (A - *Pre(pos)) >= 0) chk = true;
  return Hull.erase(pos), chk;
}
int main() {
  scanf("%d", &Q);
  Q -= 3;
  scanf("%*d%lld%lld%*d%lld%lld%*d%lld%lld", &A.X, &A.Y, &B.X, &B.Y, &C.X,
        &C.Y);
  tempX = A.X + B.X + C.X;
  tempY = A.Y + B.Y + C.Y;
  A.X = A.X * 3 - tempX;
  B.X = B.X * 3 - tempX;
  C.X = C.X * 3 - tempX;
  A.Y = A.Y * 3 - tempY;
  B.Y = B.Y * 3 - tempY;
  C.Y = C.Y * 3 - tempY;
  top = 3;
  Hull.insert(A);
  Hull.insert(B);
  Hull.insert(C);
  while (Q--) {
    scanf("%d%lld%lld", &opt, &A.X, &A.Y);
    A.X = A.X * 3 - tempX;
    A.Y = A.Y * 3 - tempY;
    if (opt & 1)
      insert(A);
    else
      puts(check(A) ? "YES" : "NO");
  }
}
