#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.0000001;
const double PI = acos(-1);
const long long INFLL = 0x7FFFFFFFFFFFFFFF;
const int INF = 0x7FFFFFFF;
template <typename T>
inline void next(T& num) {
  char c;
  num = 0;
  do {
    c = getchar_unlocked();
  } while (c != EOF && c == ' ' && c == '\n' && c == '\t');
  int sign = (c == '-' ? -1 : 1);
  if (c != '-') num += (c - '0');
  while ((c = getchar_unlocked()) != EOF && c != '\n' && c != '\t' &&
         c != ' ') {
    num *= 10;
    num += (c - '0');
  }
  num *= sign;
}
struct point {
  int x, y;
};
int sqr(int a) { return a * a; }
int dist(point a, point b) { return sqr(a.x - b.x) + sqr(a.y - b.y); }
bool operator<(const point& a, const point& b) {
  return (dist(a, point{0, 0}) > dist(b, point{0, 0}));
}
int n, r, m, total = 0;
vector<point> v, tmp, res;
void backtrack(int cur, int last, int cir) {
  if (cur >= m) return;
  if (last == n) {
    if (cir > total) {
      total = cir;
      for (int i = int(0), _b = int(n - 1); i <= _b; ++i) res[i] = tmp[i];
    }
    return;
  }
  backtrack(cur + 1, last, cir);
  tmp[last] = v[cur];
  int add = 0;
  for (int i = int(0), _b = int(last - 1); i <= _b; ++i) {
    add += dist(v[cur], tmp[i]);
  }
  backtrack(cur, last + 1, cir + add);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> r;
  for (int x = 0, y = r; x <= r; ++x) {
    while (dist(point{x, y}, point{0, 0}) > sqr(r)) y--;
    v.push_back(point{x, y});
    v.push_back(point{-x, y});
    if (y > 0) {
      v.push_back(point{x, -y});
      v.push_back(point{-x, -y});
    }
  }
  sort((v).begin(), (v).end());
  m = min((int)v.size(), 30);
  tmp.resize(n);
  res.resize(n);
  backtrack(0, 0, 0);
  cout << total << '\n';
  for (__typeof(res.begin()) i = res.begin(); i != res.end(); i++)
    cout << i->x << ' ' << i->y << '\n';
  return 0;
}
