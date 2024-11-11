#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = 1000 * 1000 * 1000 + 7;
const long long LINF = INF * (long long)INF;
struct Point {
  int x, y;
  Point() {}
  Point(int x1, int y1) {
    x = x1;
    y = y1;
  }
  int firstDig() const { return x - y; }
  int secDig() const { return x + y; }
  int par() { return secDig() & 1; }
  bool operator<(const Point& a) const { return secDig() < a.secDig(); }
};
const int MAX = 1000 * 100 + 47;
Point A[MAX];
multiset<Point> L[2];
multiset<Point> R[2];
vector<Point> M;
int n;
int pos;
bool cmp(const Point& a, const Point& b) { return a.firstDig() < b.firstDig(); }
int addToM(int dig) {
  for (int i = (pos); i < (n); i++) {
    Point a = A[i];
    if (a.firstDig() != dig) return i;
    M.push_back(a);
    int par = a.par();
    R[par].erase(R[par].find(a));
  }
  return n;
}
void addToL() {
  for (int i = (0); i < ((int)M.size()); i++) {
    int par = M[i].par();
    L[par].insert(M[i]);
  }
}
void move(int dig) {
  if (pos == n) return;
  addToL();
  M.clear();
  pos = addToM(dig);
}
int get(const multiset<Point>& L, const multiset<Point>& R, int dig) {
  if ((int)L.size() < 2 || (int)R.size() < 2) return 0;
  Point l = max(*L.begin(), *R.begin());
  Point r = min(*L.rbegin(), *R.rbegin());
  return (r.secDig() - l.secDig()) / 2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> A[i].x >> A[i].y;
  }
  sort(A, A + n, cmp);
  Point mn = A[0];
  Point mx = A[0];
  for (int i = (0); i < (n); i++) {
    int par = A[i].par();
    R[par].insert(A[i]);
    if (A[i].firstDig() < mn.firstDig()) {
      mn = A[i];
    }
    if (A[i].firstDig() > mx.firstDig()) {
      mx = A[i];
    }
  }
  long long ans = 0;
  int dig = mn.firstDig();
  int par = mn.par() ^ 1;
  while (dig <= mx.firstDig()) {
    move(dig);
    ans += get(L[par], R[par], dig);
    dig++;
    par ^= 1;
  }
  cout << ans << "\n";
  return 0;
}
