#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n & 1) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n & 1) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (T x : p) os << x << " ";
  os << "]" << endl;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "{ ";
  for (T x : p) os << x << " ";
  os << "}" << endl;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& p) {
  os << "{ ";
  for (T x : p) os << x << " ";
  os << "}" << endl;
  return os;
}
template <typename Tk, typename Tv>
ostream& operator<<(ostream& os, const map<Tk, Tv>& p) {
  os << "{ ";
  for (pair<Tk, Tv> x : p) os << x << " ";
  os << "}" << endl;
  return os;
}
template <typename Tk, typename Tv>
ostream& operator<<(ostream& os, const pair<Tk, Tv>& p) {
  os << "{" << p.first << ',' << p.second << "}";
  return os;
}
int a[14][2], b[14][2];
int r, len;
int v[14];
int fl = 0;
struct Point {
  int x;
  int y;
};
bool onSegment(Point p, Point q, Point r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
      q.y >= min(p.y, r.y))
    return true;
  return false;
}
int orientation(Point p, Point q, Point r) {
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;
  return (val > 0) ? 1 : 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);
  if (o1 != o2 && o3 != o4) return true;
  if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  return false;
}
int chk() {
  for (int i = 0; i < r; i++)
    for (int j = i + 1; j < r; j++) {
      Point p1 = {a[v[i]][0], a[v[i]][1]}, q1 = {b[i][0], b[i][1]};
      Point p2 = {a[v[j]][0], a[v[j]][1]}, q2 = {b[j][0], b[j][1]};
      if (doIntersect(p1, q1, p2, q2)) return 0;
    }
  return 1;
}
void swapp(int* x, int* y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
void f(int l, int r) {
  int i;
  if (l == r) {
    if (chk()) fl = 1;
  } else {
    for (i = l; i <= r; i++) {
      swapp((v + l), (v + i));
      f(l + 1, r);
      swapp((v + l), (v + i));
    }
  }
}
int main() {
  int i, j;
  scanf("%d", &r), scanf("%d", &j);
  if (r != j) {
    puts("-1");
    return 0;
  }
  len = r;
  for (i = 0; i < r; i++) scanf("%d", &a[i][0]), scanf("%d", &a[i][1]);
  for (i = 0; i < r; i++) scanf("%d", &b[i][0]), scanf("%d", &b[i][1]);
  for (i = 0; i < r; i++) v[i] = i;
  f(0, r - 1);
  if (fl)
    puts("Yes");
  else
    puts("No");
  return 0;
}
