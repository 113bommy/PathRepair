#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
};
point operator-(const point& a, const point& b) {
  return {a.x - b.x, a.y - b.y};
}
int sign(int x) {
  if (x < 0) return -1;
  if (x > 0) return 1;
  return 0;
}
int vecmul(const point& v1, const point& v2) {
  return v1.x * v2.y - v1.y * v2.x;
}
int vecmul(const point& a, const point& b1, const point& b2) {
  return vecmul(b1 - a, b2 - a);
}
bool intersect(const point& a1, const point& a2, const point& b1,
               const point& b2) {
  if (abs(sign(vecmul(a1, a2, a2)) - sign(vecmul(a1, a2, b2))) != 0 &&
      abs(sign(vecmul(b1, b2, a1)) - sign(vecmul(b1, b2, a2))) != 0)
    return true;
  return false;
}
bool isPossible(const vector<point>& p1, const vector<point>& p2,
                const vector<int> t) {
  for (int i = 0; i < (int)p1.size(); i++)
    for (int j = 0; j < (int)p1.size(); j++)
      if (i != j)
        if (intersect(p1[i], p2[t[i]], p1[j], p2[t[j]])) return false;
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int r, b;
  cin >> r >> b;
  if (r != b) {
    cout << "No";
    return 0;
  }
  vector<point> r_c(r), b_c(r);
  for (auto& i : r_c) cin >> i.x >> i.y;
  for (auto& i : b_c) cin >> i.x >> i.y;
  vector<int> prmt(r);
  for (int i = 0; i < r; i++) prmt[i] = i;
  do {
    if (isPossible(r_c, b_c, prmt)) {
      cout << "Yes";
      return 0;
    }
  } while (next_permutation(prmt.begin(), prmt.end()));
  cout << "No";
  return 0;
}
