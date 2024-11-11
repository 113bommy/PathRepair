#include <bits/stdc++.h>
using namespace std;
template <typename T>
T nextInt() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int maxn = (int)2e5 + 10;
const int inf = (int)1e9 + 5;
const int mod = (int)1e6 + 3;
const long long llinf = (long long)1e18 + 5;
const long double pi = acos(-1.0);
struct pt {
  long long x, y;
  bool operator<(const pt &rhs) const {
    return make_pair(x, y) < make_pair(rhs.x, rhs.y);
  }
};
int n;
pt p[maxn];
pt a, b, c;
long long sdist(pt a, pt b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
long double dist(pt a, pt b) { return sqrt(sdist(a, b)); }
multiset<pair<long double, pt>> cur;
long double solve(pt a, pt b) {
  if (n == 1) return dist(a, p[0]);
  long double ret = 1e18;
  long double sum = 0.0;
  cur.clear();
  for (int i = (0); i < (n); i++) {
    cur.insert(make_pair(dist(p[i], b) - dist(p[i], c), p[i]));
    sum += dist(p[i], c);
  }
  for (int i = (0); i < (n); i++) {
    cur.erase(cur.find(make_pair(dist(p[i], b) - dist(p[i], c), p[i])));
    ret = min(ret, dist(a, p[i]) + sum - dist(c, p[i]) +
                       min((long double)0.0, cur.begin()->first));
    cur.insert(make_pair(dist(p[i], b) - dist(p[i], c), p[i]));
  }
  return ret;
}
int main() {
  cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
  cin >> n;
  long double sum = 0.0;
  for (int i = (0); i < (n); i++) {
    cin >> p[i].x >> p[i].y;
    sum += dist(p[i], c);
  }
  cout.precision(16);
  cout << sum + min(solve(a, b), solve(b, a)) << endl;
  return 0;
}
