#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
void setIO(string name = "") {
  cin.tie(0)->sync_with_stdio(0);
  if ((int)(name).size()) {
  }
}
template <typename T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (auto& v : vec) is >> v;
  return is;
}
const int MAXN = 1e5 + 10;
const int INF = 1e9 + 1;
bool is_int(double first) { return floor(first) == first; }
void max_self(int& a, int b) { a = max(a, b); }
int gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int interstection(int x1, int y1, int x2, int y2, int x11, int y11, int x22,
                  int y22) {
  return (min(x2, x22) - max(x1, x11)) * (min(y2, y22) - max(y1, y11));
}
ll interstect(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
  return max(0ll, min(x2, x4) - max(x1, x3)) *
         max(0ll, min(y2, y4) - max(y1, y3));
}
struct rect {
  ll x1, y1, x2, y2;
  ll area() { return (x2 - x1) * (y2 - y1); }
  ll is_intesect(rect r) {
    return max(0ll, min(x2, r.x2) - max(x1, r.x1)) *
           max(0ll, min(y2, r.y2) - max(y1, r.y1));
  }
  rect intersect(rect r) {
    if (is_intesect(r))
      return rect{max(x1, r.x1), max(y1, r.y1), min(x2, r.x2), min(y2, r.y2)};
    return rect{0, 0, 0, 0};
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  rect r1, r2, r3;
  cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
  cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;
  cin >> r3.x1 >> r3.y1 >> r3.x2 >> r3.y2;
  if (r1.area() != (r1.intersect(r2).area() + r1.intersect(r3).area() -
                    r1.intersect(r2).intersect(r3).area())) {
    cout << "YES" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
