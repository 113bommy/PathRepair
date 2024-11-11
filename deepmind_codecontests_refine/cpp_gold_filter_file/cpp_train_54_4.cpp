#include <bits/stdc++.h>
const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const long long I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);
using namespace std;
int maxx, maxy, w;
int rev[100500];
int Rev(int a) {
  int res = 0;
  while (a) res = res * 10 + a % 10, a /= 10;
  return res;
}
map<pair<int, int>, int> m1;
map<pair<int, int>, int> m2;
int gcd(int a, int b) { return (b) ? gcd(b, a % b) : a; }
void inc(map<pair<int, int>, int>& m, int a, int b) {
  int g = gcd(a, b);
  a /= g;
  b /= g;
  m[make_pair(a, b)]++;
}
void dec(map<pair<int, int>, int>& m, int a, int b) {
  int g = gcd(a, b);
  a /= g;
  b /= g;
  m[make_pair(a, b)]--;
}
int get(map<pair<int, int>, int>& m, int a, int b) {
  int g = gcd(a, b);
  a /= g;
  b /= g;
  return m[make_pair(a, b)];
}
int X = -1, Y = -1;
void upd(int x, int y, int W) {
  if (W < w || 1LL * x * y >= 1LL * X * Y && X != -1) return;
  X = x;
  Y = y;
}
int main() {
  cin >> maxx >> maxy >> w;
  for (int i = 1; i <= (int)1e5; i++) rev[i] = Rev(i);
  int x;
  int y = 0;
  int W = 0;
  for (x = 1; x <= maxx; x++) inc(m1, x, rev[x]);
  x--;
  while (x > 0) {
    while (W < w && y < maxy) {
      y++;
      inc(m2, rev[y], y);
      W += get(m1, rev[y], y);
    }
    upd(x, y, W);
    dec(m1, x, rev[x]);
    W -= get(m2, x, rev[x]);
    x--;
  }
  if (X == -1)
    puts("-1");
  else
    printf("%d %d\n", X, Y);
  return 0;
}
