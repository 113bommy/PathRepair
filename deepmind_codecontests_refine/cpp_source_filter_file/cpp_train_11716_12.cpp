#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long linf = 1e18 + 5;
long long int gcd(long long int a, long long int b) {
  return (b == 0 ? a : gcd(b, a % b));
}
long long int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
long long int max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
long long int power(long long int x, long long int y) {
  long long int ans = 1;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % 1000000007;
    x = (x * x) % 1000000007;
    y /= 2;
  }
  return ans;
}
inline int read() {
  int ret = 0, temp = 1;
  int c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = (ret << 3) + (ret << 1) + c - '0';
    c = getchar();
  }
  return ret;
}
string solve(int n) {
  string s;
  while (n > 0) {
    s = char(n % 10 + 48) + s;
    n /= 10;
  }
  return s;
}
double X[N], Y[N], A[N], B[N];
double dist(pair<long long int, long long int> a,
            pair<long long int, long long int> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}
set<pair<double, int> > Adist, Bdist;
int main() {
  int n;
  double ax, ay, bx, by, tx, ty, x, y;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  cin >> n;
  double add = 0.0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    X[i] = x;
    Y[i] = y;
    add += 2 * dist({x, y}, {tx, ty});
    A[i] = dist({x, y}, {ax, ay}) - dist({x, y}, {tx, ty});
    B[i] = dist({x, y}, {bx, by}) - dist({x, y}, {tx, ty});
    Adist.insert({A[i], i});
    Bdist.insert({B[i], i});
  }
  double onlyA = 0.0, onlyB = 0.0, bothAB = 0.0;
  onlyA = add + Adist.begin()->first;
  onlyB = add + Bdist.begin()->first;
  bothAB = add;
  if (n == 1) {
    printf("%.10lf", min(onlyA, onlyB));
  } else {
    if (Adist.begin()->second == Bdist.begin()->second) {
      auto it1 = Adist.begin();
      it1++;
      auto it2 = Bdist.begin();
      it2++;
      double ans = min(Adist.begin()->first + it2->first,
                       Bdist.begin()->first + it1->first);
      bothAB += ans;
    } else
      bothAB += (Adist.begin()->first + Bdist.begin()->first);
  }
  printf("%.20lf", min(min(onlyA, onlyB), bothAB));
}
